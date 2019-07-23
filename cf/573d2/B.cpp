#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string tiles[3];
    cin >> tiles[0] >> tiles[1] >> tiles[2];
    sort(tiles, tiles + 3);

    if (tiles[0] == tiles[1] && tiles[1] == tiles[2]) {
        cout << "0\n";
        return 0;
    }

    if (tiles[0][1] == tiles[1][1] && tiles[1][1] == tiles[2][1]) {
        if (tiles[1][0] - tiles[0][0] == 1 && tiles[2][0] - tiles[1][0] == 1) {
            cout << "0\n";
            return 0;
        }
    }

    if (tiles[0] == tiles[1] || tiles[0] == tiles[2] || tiles[1] == tiles[2]){
        cout << "1\n";
        return 0;
    }

    if  (tiles[0][1] == tiles[1][1] && tiles[1][0] - tiles[0][0] == 1) {
        cout << "1\n"; return 0;
    }
    if  (tiles[0][1] == tiles[1][1] && tiles[1][0] - tiles[0][0] == 2) {
        cout << "1\n"; return 0;
    }
    if  (tiles[1][1] == tiles[2][1] && tiles[2][0] - tiles[1][0] == 1) {
        cout << "1\n"; return 0;
    }
    if  (tiles[1][1] == tiles[2][1] && tiles[2][0] - tiles[1][0] == 2) {
        cout << "1\n"; return 0;
    }
    if  (tiles[0][1] == tiles[2][1] && tiles[2][0] - tiles[0][0] == 1) {
        cout << "1\n"; return 0;
    }
    if  (tiles[0][1] == tiles[2][1] && tiles[2][0] - tiles[0][0] == 2) {
        cout << "1\n"; return 0;
    }
    cout << "2\n";

    return 0;
}
