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

char c(int N, int K, int* L) {
    if (N == 0) return 'a';
    if (N == 1) return 'b';
    if (N == 2) return 'c';

    if (K <= L[N - 1]) return c(N - 1, K, L);
    if (K <= L[N - 1] + L[N - 2]) return c(N - 2, K - L[N - 1], L);
    return c(N - 3, K - L[N - 1] - L[N - 2], L);
}

int main() {
    int N, K; cin >> N >> K;
    int L[N + 1];
    L[0] = L[1] = L[2] = 1;
    FOR (i, 3, N + 1) L[i] = L[i - 1] + L[i - 2] + L[i - 3];

    if (L[N] < K) cout << -1 << endl;
    else cout << c(N, K, L) << endl;
    return 0;
}
