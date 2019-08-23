#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const ll MD = 998244353;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> s(n);
    for (auto& x : s) cin >> x.first >> x.second;

    vector<ll> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % MD;

    vector<int> cnta(n + 1, 0), cntb(n + 1, 0);
    for (int i = 0; i < n; i++)
        cnta[s[i].first]++, cntb[s[i].second]++;

    ll A = 1, B = 1;
    for (int i = 1; i <= n; i++) {
        A = (A * fac[cnta[i]]) % MD;
        B = (B * fac[cntb[i]]) % MD;
    }

    sort(s.begin(), s.end());
    map<pair<int, int>, int> mp;
    bool good = false;
    for (int i = 0; i < n; i++) {
        if (i > 0 && (s[i].first < s[i - 1].first || s[i].second < s[i - 1].second)) {
            good = true;
            break;
        }
        mp[s[i]]++;
    }

    ll C = 0;
    if (!good) {
        C = 1;
        int m = unique(s.begin(), s.end()) - s.begin();
        for (int i = 0; i < m; i++)
            C = (C * fac[mp[s[i]]]) % MD;
    }

    ll ans = (fac[n] - A + MD) % MD;
    ans = (ans - B + MD) % MD;
    ans = (ans + C) % MD;

    cout << ans << endl;
    return 0;
}
