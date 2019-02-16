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
    io::setIO("maxcross");

    int n, k, b;
    bool sig[100000];
    cin >> n >> k >> b;
    forn (i, n) sig[i] = true;
    forn (i, b) {
        int j; cin >> j;
        sig[j - 1] = false;
    }

    int s = 0;
    forn (i, k) if (!sig[i]) s++;
    int answer = s;
    fora (i, 1, n - k + 1) {
        if (!sig[i - 1]) s--;
        if (!sig[i + k - 1]) s++;
        answer = min(answer, s); 
    }
    cout << answer << endl;
    return 0;
}