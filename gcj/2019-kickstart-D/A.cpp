#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int n, q; cin >> n >> q;
        set<int> odd;
        vector<bool> a(n);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = __builtin_popcount(x) % 2;
            if (a[i]) odd.insert(i);
        }

        for (int i = 0; i < q; i++) {
            int p, v; cin >> p >> v;
            bool o = __builtin_popcount(v) % 2;
            if (a[p] != o) {
                if (o) {
                    odd.insert(p);
                } else {
                    auto it = odd.find(p);
                    odd.erase(it);
                }
            }
            a[p] = o;

            if (odd.size() % 2 == 0) {
                ans.push_back(n);
            } else {
                ans.push_back(max(n - *odd.begin() - 1, *odd.rbegin()));
            }
        }

        cout << "Case #" << tt << ":";
        for (int x : ans) cout << " " << x;
        cout << endl;
    }

    return 0;
}
