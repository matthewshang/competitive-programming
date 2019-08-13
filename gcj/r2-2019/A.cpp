#include "bits/stdc++.h"

using namespace std;


bool ok(vector<int>& perm, vector<int>& C, vector<int>& J) {
    bool sum_ok = true;
    vector<int> sums;
    for (int i = 0; i < perm.size(); ++i)
        sums.push_back(C[i] + J[i]);
    for (int i = 0; i < perm.size() - 1; ++i)
        if (sums[i] < sums[i + 1])
            sum_ok = false;
    if (sum_ok) return true;


    int x = 0, y = 0;
    bool dir = false; // false: c < j
    for (int p = 0; p < perm.size() - 1; ++p) {
        int u = perm[p], v = perm[p + 1];
        int a = C[v] - C[u], b = J[v] - J[u];
        if (a > 0 && b > 0) continue;
        if (a <= 0 && b <= 0) return false; 

        if (a < 0) {
            x = -a;
            y = b;
            dir = false;
            break;
        }
        if (b < 0) {
            x = a;
            y = -b;
            dir = true;
            break;
        }
    }
    // cout << "bob: " << x << ", " << y << ", " << dir << endl;

    for (int p = 0; p < perm.size() - 1; ++p) {
        int u = perm[p], v = perm[p + 1];
        int a = C[v] - C[u], b = J[v] - J[u];
        if (a > 0 && b > 0) continue;
        if (a <= 0 && b <= 0) return false; 

        if (a < 0) {
            if (dir && a * x < b * y) return false;
            if (!dir && -a * x > b * y) return false;
        }
        if (b < 0) {
            if (dir && a * x < -b * y) return false;
            if (!dir && a * x > b * y) return false;
        }
    }
    return true;
}

int main() {
    int TT; cin >> TT;
    for (int tt = 1; tt <= TT; ++tt) {
        int N; cin >> N;
        int answer = 0;
        vector<int> C(N), J(N);
        for (int i = 0; i < N; ++i) cin >> C[i] >> J[i];

        vector<int> perm;
        for (int i = 0; i < N; ++i) perm.push_back(i);

        do {
            if (ok(perm, C, J)) {
                ++answer;
                // for (int i = 0; i < N; ++i) cout << C[perm[i]] << " " << J[perm[i]] << endl;
                // cout << endl;
            }
            // if (ok(perm, C, J)) {
            //     for (int i = 0; i < N; ++i) cout << C[perm[i]] << " " << J[perm[i]] << endl;
            //     cout << endl;
            // }
        } while (next_permutation(perm.begin(), perm.end()));
        
        cout << "Case #" << tt << ": " << answer << endl;
    }
    return 0;
}
