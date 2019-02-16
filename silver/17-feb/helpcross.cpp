#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

namespace io {
    void setIO(string s) {
        freopen((s + ".in").c_str(), "r", stdin);
        #ifndef TESTING 
        freopen((s + ".out").c_str(), "w", stdout);
        #endif
    }

    void pr(const vi &v) {
        forn(i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        forn(i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

typedef pair<int, pair<int, int>> piii;

int main() {
    io::setIO("helpcross");
    int c, n;
    int a[20000], b[20000];
    vector<piii> e;
    cin >> c >> n;
    forn (i, c) {
        int t; cin >> t;
        e.emplace_back(t, make_pair(1, -1));
    }
    forn (i, n) {
        cin >> a[i] >> b[i];
        e.emplace_back(a[i], make_pair(0, i));
        e.emplace_back(b[i], make_pair(2, i));
    }
    sort(e.begin(), e.end(), [](const piii& l, const piii& r) {
        if (l.fi == r.fi) return l.se.fi < r.se.fi;
        return l.fi < r.fi;
    });

    set<pii> cows;
    int answer = 0;
    for (const auto& x : e) {
        if (x.se.fi == 0) cows.insert(make_pair(b[x.se.se], x.se.se));
        if (x.se.fi == 2) cows.erase(make_pair(b[x.se.se], x.se.se));
        if (x.se.fi == 1 && cows.size() > 0) {
            cows.erase(cows.begin());
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}