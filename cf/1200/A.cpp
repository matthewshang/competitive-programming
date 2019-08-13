#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    string e; cin >> e;
    bool room[10]; for (int i = 0; i < 10; i++) room[i] = false;
    for (int i = 0; i < n; i++) {
        if (e[i] == 'L') {
            int j = 0;
            while (room[j]) j++;
            room[j] = true;
        } else if (e[i] == 'R') {
            int j = 9;
            while (room[j]) j--;
            room[j] = true;
        } else {
            int j = e[i] - '0';
            room[j] = false;
        }
    }

    for (int i = 0; i < 10; i++) cout << room[i];
    cout << endl;

    return 0;
}
