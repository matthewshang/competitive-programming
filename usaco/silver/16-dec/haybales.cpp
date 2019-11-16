#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 100000;
int n, q;
int hay[MAXN];

int search(int query, bool right) {
    int lo = 0, hi = n - 1; 
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (hay[m] == query) {
            return m;
        }
        if (hay[m] < query) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    return lo - right;
}

int main() {
    ifstream in("haybales.in");
    ofstream out("haybales.out");

    in >> n >> q;
    forn(i, n) in >> hay[i];
    sort(hay, hay + n);

    // cout << search(3) << endl;
    // cout << search(4) << endl;
    // cout << search(6) << endl;

    forn(i, q) {
        int l, r;
        in >> l >> r;
        // cout << "search(" << l << "): " << search(l, false) << " search(" << r << "): " << search(r, true) << endl;
        int idx = search(r, true) - search(l, false) + 1;
        // cout << idx << endl;
        out << idx << endl;
    }
    return 0;
}