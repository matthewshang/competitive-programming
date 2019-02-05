#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 100000;
int n;
pii shift[MAXN * 2];

int main() {
    // ifstream in("lifeguards.in");
    ifstream in("life/5.in");
    in >> n;
    forn(i, n) {
        int a, b;  in >> a >> b;
        shift[2 * i + 1].fi= a;
        shift[2 * i + 1].se= 1;
        shift[2 * i].fi = b;
        shift[2 * i].se = -1;
    }
    sort(shift, shift + n * 2);
    
    int count = 0;
    int total = 0;
    int last_empty = -1;
    int last_time = -1;
    int min_drop = INT_MAX;
    // cout << shift[n * 2 - 1].fi << ": " << shift[n * 2 - 1].se << ", " << count << endl;
    forn(i, n * 2) {
        count += shift[i].se;

        if (i < 5) cout << shift[i].fi << ": " << shift[i].se << ", " << count << endl;

        if (count > 0 && last_time == -1) {
            last_time = shift[i].fi;
        }
        
        if (count == 0 && last_time != -1) {
            total += shift[i].fi - last_time;
            last_time = -1;
        }

        if (count == 1 && last_empty == -1) {
            last_empty = shift[i].fi;
        }

        if ((count == 0 || count > 1) && last_empty != -1) {
            int drop = shift[i].fi - last_empty;
            if (drop > 0) min_drop = min(min_drop, drop);
            last_empty = -1;
        }
    }
    cout << total << endl;
    cout << total - min_drop << endl;

    ofstream out("lifeguards.out");
    out << total - min_drop << endl;
    return 0;
}