#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define F0R(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define F0Rd(i, a) for (int i = (a); i >= 0; --i)

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

    template <typename T> void pr(const vector<T> &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    FOR (tt, 1, T + 1) {
        int P, Q; cin >> P >> Q;
        int N[Q + 1], S[Q + 1], W[Q + 1], E[Q + 1];
        F0R (i, Q + 1) N[i] = S[i] = W[i] = E[i] = 0;
        F0R (i, P) {
            int X, Y; cin >> X >> Y;
            char D; cin >> D;
            if (D == 'N') ++N[Y + 1]; 
            else if (D == 'S') ++S[Y - 1];
            else if (D == 'W') ++ W[X - 1];
            else ++ E[X + 1];
        }

        FOR (i, 1, Q + 1) N[i] += N[i - 1];
        FOR (i, 1, Q + 1) E[i] += E[i - 1];
        F0Rd (i, Q - 1) S[i] += S[i + 1];
        F0Rd (i, Q - 1) W[i] += W[i + 1];

        int answer_x = 0, answer_y = 0;
        int max_x = 0, max_y = 0;
        F0R (i, Q + 1) {
            int x_val = W[i] + E[i];
            int y_val = N[i] + S[i];

            if (x_val > max_x) {
                answer_x = i;
                max_x = x_val;
            }
            if (y_val > max_y) {
                answer_y = i;
                max_y = y_val;
            }
        }
        cout << "Case #" << tt << ": " << answer_x << " " << answer_y << endl;
    }
    return 0;
}
