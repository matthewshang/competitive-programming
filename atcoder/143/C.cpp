#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int i = 0;
    while (i < n) {
        char c = s[i];
        while (i < n && s[i] == c) i++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
