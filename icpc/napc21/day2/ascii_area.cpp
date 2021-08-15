#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    int area = 0;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        bool in = false;
        for (int j = 0; j < w; j++) {
            if (s[j] == '/' || s[j] == '\\') {
                in = !in;
                area += 1;
            } else if (in) {
                area += 2;
            }
        }
    }
    cout << area / 2 << '\n';

    return 0;
}