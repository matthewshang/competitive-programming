#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h, v;
    cin >> n >> h >> v;
    int a = max(max(h * v, (n - h) * v), max(h * (n - v), (n - h) * (n - v)));
    cout << a * 4 << '\n';

    return 0;
}