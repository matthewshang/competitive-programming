#include <bits/stdc++.h>
using namespace std;

int main() {
    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;
    cout << ((wc >= ws + 2 && hc >= hs + 2) ? 1 : 0) << '\n';

    return 0;
}