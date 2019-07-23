#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    vector<int> w(s.size());
    w[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        w[i] = w[i - 1];
        if (s[i] == 'v' && s[i - 1] == 'v') w[i]++;
    }

    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o') {
            ans += (ll)w[i] * (w[s.size() - 1] - w[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
