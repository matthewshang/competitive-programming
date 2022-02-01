#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

/* Date: 2022-01-31
 * Source: UW 2022
 * Summary: For every length `l`, hash all substrings of length `l` to find
 * three that don't overlap. Binary search on `l`.
 */

constexpr int P = 257;
constexpr int MOD = 1000000007;

int modpow(int a, int b, int mod) {
    int x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) x = int64_t(x) * y % mod;
        y = int64_t(y) * y % mod;
        b /= 2;
    }
    return x;
}

struct Info {
    array<int16_t, 3> pos;

    Info() {
        pos[0] = pos[1] = pos[2] = -1;
    }

    void insert(int16_t start, int len) {
        if (pos[0] == -1) {
            pos[0] = start;
        } else if (pos[1] == -1) {
            if (pos[0] + len <= start) pos[1] = start;
        } else if (pos[2] == -1) {
            if (pos[1] + len <= start) pos[2] = start;
        }
    }

    bool has_three() const {
        return pos[2] != -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string s, line;
    getline(cin, line);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        s.append(line);
        if (i != N - 1) {
            s.push_back('\n');
        }
    }

    const int L = s.size();

    auto find_triple_repeat = [&](int l) -> int {
        gp_hash_table<int, Info> occurences;
        int hash = 0;
        for (int i = 0; i < l; i++) {
            hash = int64_t(hash) * P % MOD;
            hash = (hash + s[i] + 1) % MOD;
        }
        if (isalpha(s[0]) && isalpha(s[l - 1])) {
            occurences[hash].insert(0, l);
        }
        for (int i = 1; i + l - 1 < L; i++) {
            int rem = (int64_t)modpow(P, l - 1, MOD) * (s[i - 1] + 1) % MOD;
            hash = (hash - rem + MOD) % MOD;
            hash = int64_t(hash) * P % MOD;
            hash = (hash + s[i + l - 1] + 1) % MOD;
            if (isalpha(s[i]) && isalpha(s[i + l - 1])) {
                occurences[hash].insert(i, l);
            }
        }

        bool found = false;
        int cur_best_start = L;
        for (auto& [_, where] : occurences) {
            if (where.has_three() && where.pos[0] < cur_best_start) {
                cur_best_start = where.pos[0];
                found = true;
            }
        }

        return found ? cur_best_start : L;
    };

    int lo = 1;
    int hi = L / 3;
    while (lo < hi) {
        const int l = lo + (hi - lo + 1) / 2;
        const int cur_best_start = find_triple_repeat(l);
        if (cur_best_start != L) {
            lo = l;
        } else {
            hi = l - 1;
        }
    }

    int best_start = find_triple_repeat(lo);
    if (best_start != L) {
        cout << s.substr(best_start, lo) << '\n';
    }

    return 0;
}