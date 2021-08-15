#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int s = floor(sqrt(n));
    cout << "The largest square has side length " << s << "." << endl;

    return 0;
}