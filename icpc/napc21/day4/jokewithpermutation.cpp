#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int m = s.size();
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        d[i] = s[i] - '0';
    }
    int n;
    if (m > 9) {
        n = (m - 9) / 2 + 9;
    } else {
        n = m;
    }

    vector<bool> used(n + 1);
    vector<int> p;
    function<bool(int)> go = [&](int i) -> bool {
        if (i >= m) {
            for (int j = 1; j <= n; j++) {
                if (!used[j]) return false;
            }
            return true;
        }

        if (!used[d[i]]) {
            used[d[i]] = true;
            p.push_back(d[i]);
            if (go(i + 1)) return true;
            used[d[i]] = false;
            p.pop_back();
        }

        if (i < m - 1) {
            int x = d[i] * 10 + d[i + 1];
            if (!used[x]) {
                used[x] = true;
                p.push_back(x);
                if (go(i + 2)) return true;
                used[x] = false;
                p.pop_back();
            }
        }

        return false;
    };

    go(0);
    cout << p[0];
    for (int i = 1; i < n; i++) {
        cout << ' ' << p[i];
    }
    cout << '\n';

    return 0;
}