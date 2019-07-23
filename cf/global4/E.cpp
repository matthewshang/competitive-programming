#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    int C[n];
    for (int i = 0; i < n; i++) C[i] = s[i] - 'a';
    int L[n][3], R[n][3];
    const int INF = 10000000;
    for (int j = 0; j < 3; j++) {
        int last = INF;
        for (int i = n - 1; i >= 0; i--) {
            if (C[i] == j) last = i;
            if (last == INF) L[i][j] = INF;
            else L[i][j] = last - i;
        }
        last = INF;
        for (int i = 0; i < n; i++) {
            if (C[i] == j) last = i;
            if (last == INF) R[i][j] = INF;
            else R[i][j] = i - last;
        }
    }

    int p = 0, q = n - 1;
    string half = "";
    while (true) {
        if (p >= q) break;
        bool poss = false;
        for (int j = 0; j < 3; j++) {
            if (L[p][j] != INF && R[q][j] != INF &&
                p + L[p][j] < q && q - R[q][j] > p) poss = true;
        }
        if (!poss) break;

        if (C[p] == C[q]) {
            half += (char)('a' + C[p]);
            p++; q--;
        } else {
            vector<pair<ll, int>> cost;
            for (int j = 0; j < 3; j++) {
                cost.emplace_back((ll)L[p][j] * L[p][j] + (ll)R[q][j] * R[q][j], j);
            }
            sort(cost.begin(), cost.end());
            int j = cost[0].second;
            if (p + L[p][j] >= q - R[q][j]) break;
            half += (char)('a' + j);
            p += L[p][j] + 1; q -= R[q][j] + 1;
        }
    }

    string ans = half;
    if (p <= q) {
        ans += (char)('a' + C[p]);
    }
    reverse(half.begin(), half.end());
    ans += half;

    if (ans.size() >= n / 2) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
