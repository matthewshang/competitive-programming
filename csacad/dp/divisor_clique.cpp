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

int main() {
    int N; cin >> N;
    vi a(N);
    F0R (i, N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    // Find longest subsequence such that S[i] divides S[i + 1]
    int sz[N];
    int answer = 1;
    F0R (i, N) sz[i] = 1;
    FOR (i, 1, N) {
        int j = i - 1;
        while (j >= 0) {
            if (a[i] % a[j] == 0) {
                sz[i] = sz[j] + 1;
                break;
            } 
            --j;
        }
        answer = max(answer, sz[i]);
    }
    cout << answer << endl;
    return 0;
}
