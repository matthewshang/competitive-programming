#include "bits/stdc++.h"

using namespace std;

using ll = long long;

vector<int> count(string& s) {
    vector<int> c(26, 0);
    for (int i = 0; i < s.size(); i++) {
        c[s[i] - 'a']++;
    }
    return c;
}

bool solve(string& s, string& t, string& p) {
    int j = 0;
    for (int i = 0; i < t.size() && j < s.size(); i++) {
        if (s[j] == t[i]) j++;
    }
    if (j != s.size()) return false;

    vector<int> cs = count(s), ct = count(t), cp = count(p);
    for (int i = 0; i < 26; i++) {
        if (cs[i] + cp[i] < ct[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    for (int qq = 0; qq < q; qq++) {
        string s, t, p; cin >> s >> t >> p;
        if (solve(s, t, p)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
