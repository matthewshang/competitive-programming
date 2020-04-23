#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 5e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int A, B, C; cin >> A >> B >> C;
        vll a(A), b(B), c(C);
        F0R (i, A) cin >> a[i];
        F0R (i, B) cin >> b[i];
        F0R (i, C) cin >> c[i];
        // sort(all(a)); sort(all(b)); sort(all(c));
        // int i = 0, j = 0, k = 0;
        ll best = INF;

        // auto val = [&](int i_, int j_, int k_) -> ll {
        //     ll x = a[i_], y = b[j_], z = c[k_];
        //     return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
        // };
        auto val = [&](int i_, int j_, int k_) -> ll {
            ll x = i_, y = j_, z = k_;
            return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
        };

        set<int> as, bs, cs;
        F0R (i, A) as.insert(a[i]);
        F0R (i, B) bs.insert(b[i]);
        F0R (i, C) cs.insert(c[i]);
        F0R (i, A) {
            auto itb = bs.lower_bound(a[i]);
            auto itc = cs.lower_bound(a[i]);
            // if (itb == bs.end()) itb = prev(itb);
            // if (itc == cs.end()) itc = prev(itc);
            if (itb != bs.end() && itc != cs.end()) best = min(best, val(a[i], *itb, *itc));
            // cout << a[i] << " " << *itb << " " << *itc << endl;
            auto itd = (itb != bs.begin()) ? prev(itb) : itb;
            if (itc != cs.end()) best = min(best, val(a[i], *itd, *itc));
            if (itc != cs.begin()) itc = prev(itc);
            best = min(best, val(a[i], *itb, *itc));
            best = min(best, val(a[i], *itd, *itc));
            
            // best = min(best, val(a[i], *itb, *itc));
        }
        F0R (i, B) {
            auto ita = as.lower_bound(b[i]);
            auto itc = cs.lower_bound(b[i]);
            if (ita != as.end() && itc != cs.end()) best = min(best, val(b[i], *ita, *itc));
            auto itd = (ita != as.begin()) ? prev(ita) : ita;
            if (itc != cs.end()) best = min(best, val(b[i], *itd, *itc));
            if (itc != cs.begin()) itc = prev(itc);
            best = min(best, val(b[i], *ita, *itc));
            best = min(best, val(b[i], *itd, *itc));
        }
        F0R (i, C) {
            auto ita = as.lower_bound(c[i]);
            auto itb = bs.lower_bound(c[i]);
            if (ita != as.end() && itb != bs.end()) best = min(best, val(c[i], *ita, *itb));
            auto itd = (ita != as.begin()) ? prev(ita) : ita;
            if (itb != bs.end()) best = min(best, val(c[i], *itd, *itb));
            if (itb != bs.begin()) itb = prev(itb);
            best = min(best, val(c[i], *ita, *itb));
            best = min(best, val(c[i], *itd, *itb));
        }
        cout << best << nl;

        // while (j < B && k < C) {
        //     best = min(best, val(i, j, k));
        //     bool cha = false;
        //     while (k < C - 1 && c[k] < a[i]) {
        //         k++;
        //         cha = true;
        //         best = min(best, val(i, j, k));
        //     }
        //     while (j < B - 1 && b[j] < a[i]) {
        //         j++;
        //         cha = true;
        //         best = min(best, val(i, j, k));
        //     }
        //     if (!cha) i++;
        //     if (i == A) break;
        // }
        // i = A - 1;
        // while (j < B && k < C) {
        //     best = min(best, val(i, j, k));
        //     bool cha = false;
        //     while (k < C - 1 && c[k] < b[j]) {
        //         k++;
        //         cha = true;
        //         best = min(best, val(i, j, k));
        //     }
        //     if (!cha) j++;
        //     if (j == B) break;
        // }
        // j = B - 1;
        // while (k < C) {
        //     best = min(best, val(i, j, k));
        //     k++;
        // }

        // cout << best << nl;
    }

    return 0;
}