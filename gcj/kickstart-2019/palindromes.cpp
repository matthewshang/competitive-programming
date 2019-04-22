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
    void pr(const vi &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

struct BIT {
    int n;
    int* b;

    BIT() {}

    BIT(int _n) : n(_n) {
        b = new int[n + 1];
        F0R (i, n + 1) b[i] = 0; 
    }

    void update(int i, int v) {
        i++;
        for (; i <= n; i += i&-i)
            b[i] += v;
    }

    int query(int i) {
        i++;
        int s = 0;
        for (; i > 0; i -= i&-i)
            s += b[i];
        return s;
    }
};

bool ok(int count[26], int L) {
    if (L % 2 == 0) {
        F0R (i, 26) if (count[i] % 2 == 1) return false;
        return true;
    } else {
        bool odd = false;
        F0R (i, 26) {
            if (count[i] % 2 == 1) {
                if (odd) return false;
                odd = true;
            }
        }
        return true;
    }
}

int main() {
    int T; cin >> T;
    FOR (tt, 1, T + 1) {
        int N, Q; cin >> N >> Q;
        string S; cin >> S;

        BIT* letters = new BIT[26];
        F0R (i, 26) letters[i] = BIT(N);
        F0R (i, N) {
            letters[S[i] - 'A'].update(i, 1);
        }

        int answer = 0;
        F0R (i, Q) {
            int L, R; cin >> L >> R;
            int count[26];
            F0R (j, 26) {
                count[j] = letters[j].query(R - 1) - letters[j].query(L - 2);
            }

            if (ok(count, R - L + 1)) ++answer;
            
        }

        cout << "Case #" << tt << ": " << answer << endl;
    }
    return 0;
}
