#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

/* Date: 2022-02-14
 * Source: SWERC 2009
 * Summary: Binary search on answer + hashing. See UW 2022 Chorus Time.
 */

constexpr int H = 2;
using Hash = array<int, H>;
constexpr Hash P = {257, 263};
constexpr Hash MOD = {1000000007, 998244353};

int modpow(int a, int b, int mod) {
    int x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) x = int64_t(x) * y % mod;
        y = int64_t(y) * y % mod;
        b /= 2;
    }
    return x;
}

struct PairHasher {
    size_t operator()(const Hash& h) const {
        return hash<int>()(h[0]) ^ hash<int>()(h[1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int m;
        cin >> m;
        if (m == 0) {
            break;
        }
        string s;
        cin >> s;
        const int L = s.size();

        auto find_repeated = [&](int l) -> int {
            gp_hash_table<Hash, pair<int, int>, PairHasher> occurences;
            Hash hash{};
            for (int i = 0; i < l; i++) {
                for (int h = 0; h < H; h++) {
                    hash[h] = int64_t(hash[h]) * P[h] % MOD[h];
                    hash[h] = (hash[h] + s[i] + 1) % MOD[h];
                }
            }
            occurences[hash] = {1, 0};

            for (int i = 1; i + l - 1 < L; i++) {
                for (int h = 0; h < H; h++) {
                    int rem = (int64_t)modpow(P[h], l - 1, MOD[h]) * (s[i - 1] + 1) % MOD[h];
                    hash[h] = (hash[h] - rem + MOD[h]) % MOD[h];
                    hash[h] = int64_t(hash[h]) * P[h] % MOD[h];
                    hash[h] = (hash[h] + s[i + l - 1] + 1) % MOD[h];
                }
                occurences[hash].first++;
                occurences[hash].second = i;
            }

            bool found = false;
            int cur_best_start = -1;
            for (auto& [_, info] : occurences) {
                const int count = info.first;
                const int where = info.second;
                if (count >= m && where > cur_best_start) {
                    cur_best_start = where;
                    found = true;
                }
            }

            return found ? cur_best_start : L;
        };

        int lo = 1;
        int hi = L - m + 1;
        while (lo < hi) {
            const int l = lo + (hi - lo + 1) / 2;
            if (find_repeated(l) != L) {
                lo = l;
            } else {
                hi = l - 1;
            }
        }

        int best_start = find_repeated(lo);
        if (best_start == L) {
            cout << "none\n";
        } else {
            cout << lo << " " << best_start << "\n";
        }
    }

    return 0;
}