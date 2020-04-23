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

int digit(int n, int place) {
    return (n % (int)pow(10, place + 1)) / (int)pow(10, place);
}

int len(int n) {
    return (int) floor(log10((double)n)) + 1;
}

bool ok(int n) {
    if (n == 4) return false;
    F0R (i, len(n)) if (digit(n, i) == 4) return false;
    return true;
}

int largest(int n) {
    F0Rd (i, len(n) - 1) if (digit(n, i) == 4) return i;
    return -1;
}

int main() {
    int N; cin >> N;

    F0R (i, N) {
        int M; cin >> M;
        int a = M, b = 0;
        while (!ok(a) || !ok(b)) {
            if (!ok(a)) {
                int c = a % (int)pow(10, largest(a) + 1) - 4 * (int)pow(10, largest(a)) + 1;
                a -= c; b += c;
            }
            if (!ok(b)) {
                int c = 5 * (int)pow(10, largest(b)) - b % (int)pow(10, largest(b) + 1);
                a -= c; b += c;
            }
        }
        cout << "Case #" << i + 1 << ": " << a << " " << b << endl;
    }

    return 0;
}
