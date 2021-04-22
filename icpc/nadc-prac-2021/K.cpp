#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W; cin >> W;
    int N; cin >> N;
    int a = 0;
    for (int i = 0; i < N; i++) {
        int w, l; cin >> w >> l;
        a += w * l;
    }
    cout << (a / W) << '\n';

    return 0;
}
