#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K; cin >> N >> K;
        vector<int> P(N);
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        sort(P.begin(), P.end());
        N = unique(P.begin(), P.end()) - P.begin();
        P.resize(N);
        P.insert(P.begin(), 0);
        P.push_back(K + 1);

        vector<int> mids{0, 0};
        int left_end = 0;
        int right_end = 0;
        for (int i = 1; i <= N + 1; i++) {
            int count = P[i] - P[i - 1] - 1;
            if (i == 1) {
                left_end = count;
            } else if (i == N + 1) {
                right_end = count;
            } else {
                mids.push_back(count);
            }
        }
        sort(mids.begin(), mids.end(), greater<int>());

        int best = max({ mids[0], left_end + (mids[0] + 1) / 2, 
                                  right_end + (mids[0] + 1) / 2, 
                                  left_end + right_end, 
                                  (mids[0] + 1) / 2 + (mids[1] + 1) / 2 });
        cout << "Case #" << tc << ": ";
        cout << fixed << setprecision(6) << (double(best) / K) << endl;
    }

    return 0;
}