#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
vector<int> dp(MAXN + 1);

void solve(int test_case) {
    int N;
    cin >> N;
    int best = 1;
    for (int j = 2; j * j <= N; j++) {
        if (N % j == 0) {
            if (j >= 3) {
                best = max(best, dp[N / j - 1] + 1);
            }
            if (N / j >= 3) {
                best = max(best, dp[j - 1] + 1);
            }
        }
    }
    cout << "Case #" << test_case << ": " << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> spf(MAXN + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 4; i <= MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; (long long)i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    for (int i = 2; i <= MAXN; i++) {
        dp[i] = 1;
        vector<pair<int, int>> divs;
        int j = i;
        int last = -1;
        while (j != 1) {
            if (spf[j] != last) {
                divs.push_back({ spf[j], 0 });
            }
            divs.back().second++;
            last = spf[j];
            j /= spf[j];
        }
        int l = divs.size();

        vector<int> cnt(l, 0);
        vector<int> fac(l, 1);
        while (cnt[0] <= divs[0].second) {
            int d = 1;
            for (int k = 0; k < l; k++) {
                d *= fac[k];
            }

            if (d >= 2 && i / d > 1) {
                dp[i] = max(dp[i], dp[i / d - 1] + 1);
            }

            cnt[l - 1]++;
            fac[l - 1] *= divs[l - 1].first;
            for (int k = l - 1; k >= 1; k--) {
                if (cnt[k] > divs[k].second) {
                    cnt[k] = 0;
                    fac[k] = 1;
                    cnt[k - 1]++;
                    fac[k - 1] *= divs[k - 1].first;
                }
            }
        }
    }

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}
