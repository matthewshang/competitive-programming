#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;
    set<string> subs;
    for (int i = 0; i < int(s.size()); i++) {
        for (int j = i; j < int(s.size()); j++) {
            subs.insert(s.substr(i, j - i + 1));
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> s;
        for (auto it = subs.begin(); it != subs.end(); ) {
            if (s.find(*it) == string::npos) {
                it = subs.erase(it);
            } else {
                ++it;
            }
        }
    }

    int longest = 0;
    for (const auto& sub : subs) {
        longest = max(longest, int(sub.length()));
    }
    cout << longest << '\n';

    return 0;
}