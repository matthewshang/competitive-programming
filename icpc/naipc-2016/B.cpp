#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    vector<int> end(n, -1);
    stack<int> open;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            open.push(i);
        } else {
            int begin = open.top();
            open.pop();
            end[begin] = i;
        }
    }

    vector<int> L(100000);
    for (int i = 1, e = 1; i < 100000; i *= 10, e++) {
        for (int j = i; j < 10 * i; j++) {
            L[j] = e;
        }
    }

    function<string(int, int, int)> solve = [&](int l, int r, int off) -> string {
        if (end[l] == l + 1 && l + 1 == r) {
            if (L[off + 2 * L[off] + 2] == L[off]) {
                int where = off + 2 * L[off] + 2;
                return to_string(where) + "," + to_string(where) + ":";
            } else {
                int where = off + 2 * L[off] + 4;
                return to_string(where) + "," + to_string(where) + ":";
            }
        }

        if (end[l] == r) {
            // Lower bound
            int try_begin = off + L[off + 2 + 2 * L[off]] + 2 + L[off + 2 + 2 * L[off] + (r - l - 1) * (L[off] + 1)];
            while (true) {
                string res = solve(l + 1, r - 1, try_begin);
                int try_end = try_begin + res.size();
                if (L[try_begin] + L[try_end] + 2 == try_begin - off) {
                    return to_string(try_begin) + "," + to_string(try_end) + ":" + res;
                }
                try_begin++;
            }
        } else {
            string res;
            int i = l;
            while (i < r) {
                res += solve(i, end[i], off + res.size());
                i = end[i] + 1;
            }
            return res;
        }
    };

    string ans = solve(0, n - 1, 0);
    cout << ans << '\n';

    return 0;
}