#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int n, m, r;
int* cow;
pii* store;
int* rent;

ll store_profit(ll gals) {
    ll p = 0;
    int i = 0;
    while (gals > 0) {
        if (gals > store[i].se) {
            p += (ll)store[i].fi * (ll)store[i].se;
            gals -= (ll)store[i].se;
        } else {
            p += gals * (ll)store[i].fi;
            gals = 0;
        }
        i++;
    }
    return p;
}

int main() {
    ll total_rent = 0;

    ifstream in("rental.in");
    in >> n >> m >> r;
    cow = new int[n];
    store = new pii[m];
    rent = new int[r];
    forn(i, n) in >> cow[i];
    forn(i, m) in >> store[i].se >> store[i].fi;
    forn(i, r) {
        in >> rent[i]; 
        total_rent += (ll)rent[i]; 
    }
    sort(cow, cow + n, greater<int>());
    sort(store, store + m, greater<pii>()); 
    sort(rent, rent + r);

    // forn(i, n) cout << cow[i] << " ";
    // cout << endl;
    // forn(i, m) cout << store[i].fi << ", " << store[i].se << endl;
    // forn(i, r) cout << rent[i] << " ";
    // cout << endl;

    ll max_profit = 0;
    ll total_gals = 0;
    forn(i, n + 1) {
        // cout << "rent: " << total_rent << " gals: " << total_gals << endl;
        ll profit = store_profit(total_gals) + total_rent;
        max_profit = max(max_profit, profit);
        // cout << "cow: " << i << " profit: " << profit << endl;
        if (n - i - 1 < r) total_rent -= rent[i - (n - r)];
        if (i < n) total_gals += cow[i];
    }
    // cout << max_profit << endl;

    ofstream out("rental.out");
    out << max_profit << endl;
    return 0;
}