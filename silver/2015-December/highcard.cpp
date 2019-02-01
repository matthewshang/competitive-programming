#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 50000;
int n;
bool card[MAXN * 2];

int main() {
    ifstream in ("highcard.in");
    in >> n;
    forn(i, n * 2) card[i] = false;
    forn(i, n) {
        int j;  in >> j;
        card[j - 1] = true;
    }
    // forn(i, n * 2) cout << card[i];
    // cout << endl;

    int points = 0;
    int r = n * 2 - 1;
    while (card[r]) r--;
    int l = r;
    while (!card[l]) l--;

    while (true) {
        points++;
        do {
            r--;
        } while (r > 0 && card[r]);
        if (r <= 0) break;

        do {
            l--;
        } while (l >= 0 && !card[l]);
        if (l < 0) break;

        if (l >= r) {
            while (card[r]) r--;
            l = r;
            while (!card[l]) l--;
        }

        // forn(i, n * 2) cout << card[i];
        // cout << endl;
        // forn(i, l) cout << " ";
        // cout << "l";
        // forn(i, r - l - 1) cout << " ";
        // cout << "r" << endl;
    }

    ofstream out("highcard.out");
    out << points << endl;
    return 0;
}