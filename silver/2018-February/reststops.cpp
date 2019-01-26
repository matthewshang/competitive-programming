#include "bits/stdc++.h"

using namespace std;

#define MAXN 100000

typedef long long ll;

int L, N, F, B;
int x[MAXN];
int c[MAXN];
bool is_max[MAXN];

int main() {
    ifstream in("reststops.in");
    in >> L >> N >> F >> B;
    for (int i = 0; i < N; i++) {
        in >> x[i] >> c[i];
    }

    int max_c = c[N - 1];
    for (int i = N - 1; i >= 0; i--) {
        max_c = max(max_c, c[i]); 
        is_max[i] = max_c == c[i];
    }

    ll total = 0;
    int b = 0;
    for (int i = 0; i < N; i++) {
        if (is_max[i]) {
            total += (ll) c[i] * (ll) (F - B) * (ll) (x[i] - b);
            b = x[i];
        }
    }

    ofstream out("reststops.out");
    out << total << endl;
    // cout << total << endl;

    return 0;
}