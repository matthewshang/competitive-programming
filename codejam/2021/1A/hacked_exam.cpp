#include "bits/stdc++.h"
using namespace std;

// Passes Test Set 1
void solve(int test_case) {
    int N, Q; cin >> N >> Q;
    vector<string> A(N);
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> S[i];
    }

    int seqs = 0;
    vector<array<int, 2>> cnt(Q);
    for (int mask = 0; mask < (1 << Q); mask++) {
        vector<int> a(N);
        for (int z = 0; z < N; z++) {
            for (int i = 0; i < Q; i++) {
                if (((mask & (1 << i)) && A[z][i] == 'T')
                        || (!(mask & (1 << i)) && A[z][i] == 'F')) {
                    a[z]++;
                }
            }
        }

        bool good = true;
        for (int z = 0; z < N; z++) {
            if (a[z] != S[z]) {
                good = false;
            }
        }
        if (good) {
            seqs++;
            for (int i = 0; i < Q; i++) {
                if (mask & (1 << i)) {
                    cnt[i][1]++;
                } else {
                    cnt[i][0]++;
                }
            }
        }
    }

    string ans;
    int num = 0;
    for (int i = 0; i < Q; i++) {
        if (cnt[i][0] > cnt[i][1]) {
            ans += 'F';
        } else {
            ans += 'T';
        }
        num += max(cnt[i][0], cnt[i][1]);
    }
    int g = gcd(seqs, num);
    num /= g;
    seqs /= g;
    cout << "Case #" << test_case << ": " << ans << ' ' << num << '/' << seqs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }
    
    return 0;
}