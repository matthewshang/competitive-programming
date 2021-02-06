#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef gp_hash_table<int, int, hash<int>, equal_to<int>, direct_mod_range_hashing<int>, linear_probe_fn<>,
                      hash_standard_resize_policy<hash_prime_size_policy, hash_load_check_resize_trigger<true>, true>>
    gp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    gp fen;
    const int M = 1e9 + 2;
    auto upd = [&](int pos, int inc) {
        for (pos++; pos < M; pos += pos & -pos) {
            fen[pos] += inc;
        }
    };

    auto qry = [&](int pos) -> int {
        int res = 0;
        for (pos++; pos > 0; pos -= pos & -pos) {
            res += fen[pos];
        }
        return res;
    };

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        upd(p[i], 1);
    }

    while (q--) {
        char op; cin >> op;
        if (op == '?') {
            int a, b; cin >> a >> b;
            cout << (qry(b) - qry(a - 1)) << '\n';
        } else {
            int k, x; cin >> k >> x;
            upd(p[k], -1);
            upd(x, 1);
            p[k] = x;
        }
    }
}