#include <bits/stdc++.h>
using namespace std;

// Greedy. The main observation is that if we encounter a substring with
// everything in the alphabet, then the substring can be covered by taking
// the last letter. After going through the whole string, just add an unused
// letter. This is optimal because we skip as much of the original string
// as possible with every letter of the output string.

const string ALPH = "ACGT";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, ans;
    cin >> s;
    set<char> active;
    for (char c : s) {
        active.insert(c);
        if (active.size() == ALPH.size()) {
            ans += c;
            active.clear();
        } 
    }

    for (char l : ALPH) {
        if (active.find(l) == active.end()) {
            ans += l;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}
