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

int main() {
    io::setIO("lasers");
    int n;
    pii laser, barn;
    vector<pii> points;
    unordered_map<int, vi> x, y;

    cin >> n >> laser.fi >> laser.se >> barn.fi >> barn.se;
    forn (i, n) {
        int a, b; cin >> a >> b;
        points.emplace_back(a, b);
        x[a].push_back(i);
        y[b].push_back(i);
    }

    queue<pii> q;
    set<int> seen;
    int answer = INT_MAX;
    for (int i : x[barn.fi]) q.emplace(i, 1);
    for (int i : y[barn.se]) q.emplace(i, 1);
    while (!q.empty()) {
        pii p = q.front();
        q.pop();

        int i = p.fi;

        if (seen.find(i) != seen.end()) continue;
        seen.insert(i);

        if (points[i].fi == laser.fi || points[i].se == laser.se) {
            answer = min(answer, p.se);
            break;
        } else {
            for (int j : x[points[i].fi]) q.emplace(j, p.se + 1);
            for (int j : y[points[i].se]) q.emplace(j, p.se + 1);
        }
    }
    cout << (answer == INT_MAX ? -1 : answer) << endl;
    
    return 0;
}