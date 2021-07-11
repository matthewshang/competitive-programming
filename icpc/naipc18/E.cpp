#include <bits/stdc++.h>
using namespace std;

// Recover the words used with rolling hash. Then it's just some combo: we're
// given p_1,...p_k chosen from [n] and want to know the number of choices
// of k distinct from [n] that are lexicographically smaller. Go through all
// prefixes; the contribution from p_i is (# unused less than p_i) * (# choices
// of k-i from n-i left).

struct BIT { // Operation must be reversible
    int n;
    vector<int> bit;
    BIT(int n) : n{n}, bit(n) {}
    int query(int pos) { // sum from [0, pos]
        int ans = 0;
        for (pos++; pos > 0; pos &= pos - 1) ans += bit[pos - 1];
        return ans;
    }
    void update(int pos, int delta) { // a[pos] += delta; 
        for (; pos < n; pos |= pos + 1) bit[pos] += delta;
    }
};

constexpr int NUM_MODS = 2;
const array<int, NUM_MODS> P = {31, 37};
const array<int, NUM_MODS> MODS = {int(1e9) + 7, int(1e9) + 9};
using Hash = array<int64_t, NUM_MODS>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<string> ss(n);
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
    }
    sort(ss.begin(), ss.end());

    map<Hash, int> hash_to_str;
    for (int i = 0; i < n; i++) {
        Hash h{};
        Hash p_pow;
        fill(p_pow.begin(), p_pow.end(), 1);
        for (char c : ss[i]) {
            for (int j = 0; j < NUM_MODS; j++) {
                h[j] = (h[j] + (c - 'a' + 1) * p_pow[j]) % MODS[j];
                p_pow[j] = (p_pow[j] * P[j]) % MODS[j];
            }
        }
        hash_to_str[h] = i;
    }

    string t;
    cin >> t;

    vector<int> ord;
    Hash cur_hash{};
    Hash cur_pow{};
    fill(cur_pow.begin(), cur_pow.end(), 1);
    for (char c : t) {
        for (int j = 0; j < NUM_MODS; j++) {
            cur_hash[j] = (cur_hash[j] + (c - 'a' + 1) * cur_pow[j]) % MODS[j];
            cur_pow[j] = (cur_pow[j] * P[j]) % MODS[j];
        }
        if (auto it = hash_to_str.find(cur_hash); it != hash_to_str.end()) {
            ord.push_back(it->second);
            fill(cur_hash.begin(), cur_hash.end(), 0);
            fill(cur_pow.begin(), cur_pow.end(), 1);
        }
    }
    assert(int(ord.size()) == k);

    constexpr int MOD = 1e9 + 7;
    vector<int64_t> fac(k);
    fac[0] = 1;
    for (int i = 1; i < k; i++) {
        fac[i] = fac[i - 1] * (n - k + i) % MOD;
    }
    reverse(fac.begin(), fac.end());

    BIT unused(n);
    int64_t pos = 1;
    for (int i = 0; i < k; i++) {
        unused.update(ord[i], 1);
        int num_less = ord[i] + 1 - unused.query(ord[i]);
        pos += fac[i] * num_less % MOD;
        pos %= MOD;
    }
    cout << pos << '\n';

    return 0;
}
