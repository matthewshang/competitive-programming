#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int query(int a[100]) {
    cout << "? ";
    for (int i = 0; i < 100; i++)
        cout << a[i] << " ";
    cout << endl;
    int b; cin >> b;
    return b;
}

void answer(int x) {
    cout << "! " << x << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int a[100];
    for (int i = 0; i < 100; i++)
        a[i] = i;
    int b = query(a);
    
    for (int i = 0; i < 100; i++)
        a[i] = (i + 1) << 7;
    int c = query(a);

    int ans = ((b & 0b11111110000000) | (c & 0b00000001111111));
    answer(ans);

    return 0;
}
