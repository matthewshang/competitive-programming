#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-05
 * Source: PACNW 2022
 * Notes: Greedily find the minimal length missing subsequence, then answer
 * the queries quickly by precomputing a jump table storing the next position of
 * a character.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string v, s;
    cin >> v >> s;
    const int k = v.size();
    const int n = s.size();

    set<char> cur;
    string seq;
    for (int i = 0; i < n; i++) {
        cur.insert(s[i]);
        if (int(cur.size()) == k) {
            seq.push_back(s[i]);
            cur.clear();
        }
    }
    int shortest = seq.size() + 1;

    vector<array<int, 26>> next(n + 1);
    for (int j = 0; j < 26; j++) {
        next[n][j] = -1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            next[i][j] = next[i + 1][j];
        }
        next[i][s[i] - 'a'] = i + 1;
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        if (int(t.size()) != shortest) {
            cout << 0 << "\n";
        } else {
            int pos = 0;
            reverse(t.begin(), t.end());
            while (!t.empty() && pos != -1) {
                pos = next[pos][t.back() - 'a'];
                if (pos != -1) {
                    t.pop_back();
                }
            }
            cout << (!t.empty()) << "\n";
        }
    }

    return 0;
}