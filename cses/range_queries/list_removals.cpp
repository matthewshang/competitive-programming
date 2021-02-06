#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    vector<int> a(n + 2);
    auto upd = [&](int pos, int inc) {
        for (pos++; pos < n + 2; pos += pos & -pos) {
            a[pos] += inc;
        }
    };

    auto qry = [&](int pos) -> int {
        int res = 0;
        for (pos++; pos > 0; pos -= pos & -pos) {
            res += a[pos];
        }
        return res;
    };

    for (int i = 1; i <= n; i++) {
        upd(i, 1);
    }

    vector<int> ord;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (qry(mid) < p) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        ord.push_back(x[low]);
        upd(low, -1);
    }

    for (int x : ord) {
        cout << x << ' ';
    }
    cout << '\n';
}