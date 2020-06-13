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
using namespace io;

const int MAXN = 100000;
int n;  LL m;
int f[MAXN], s[MAXN];

int main() {
    setIO("hayfeast");
    cin >> n >> m;
    forn (i, n) cin >> f[i] >> s[i];

    deque<int> dq;
    LL sum = 0;
    int lo = 0, hi = 0;
    int answer = INT_MAX;
    while (hi < n) {
        while (hi < n && sum < m) {
            while (!dq.empty() && s[dq.back()] <= s[hi]) {
                dq.pop_back();
            }
            sum += f[hi];
            dq.push_back(hi++);
        }

        if (sum >= m) {
            answer = min(answer, s[dq.front()]);
        }

        while (lo <= dq.front()) {
            sum -= f[lo++];
        }
        dq.pop_front();
    }
    cout << answer << endl;

    return 0;
}