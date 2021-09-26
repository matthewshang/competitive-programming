#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-09-25
 * Source: FB Hacker Cup 2021 R2
 * Summary: Greedy while keeping track of each model's style and whether they've
 * used the free change. Priority based on:
 * - it can only be worse to not reuse a model for a style.
 * - it can only be worse to use a paid change when free changes are available.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;
		vector<int> S(M);
		for (int i = 0; i < M; i++) {
			cin >> S[i];
		}
		vector<multiset<int>> P(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int x;
				cin >> x;
				P[i].insert(x);
			}
		}

		vector<bool> used_free(M);
		int changes = 0;
		for (int i = 0; i < N; i++) {
			vector<bool> vis(M);

			// Pass 1: Reuse models who already used the free change.
			for (int j = 0; j < M; j++) {
				if (used_free[j]) {
					if (auto it = P[i].find(S[j]); it != P[i].end()) {
						P[i].erase(it);
						vis[j] = true;
					}
				}
			}

			// Pass 2: Reuse models in general.
			for (int j = 0; j < M; j++) {
				if (vis[j]) {
					continue;
				}
				if (auto it = P[i].find(S[j]); it != P[i].end()) {
					P[i].erase(it);
					vis[j] = true;
				}
			}

			// Pass 3: Have to use the free change or pay.
			for (int j = 0; j < M; j++) {
				if (vis[j]) {
					continue;
				}
				S[j] = *P[i].begin();
				P[i].erase(P[i].begin());
				if (used_free[j]) {
					changes++;
				} else {
					used_free[j] = true;
				}
			}
		}

		cout << "Case #" << tc << ": " << changes << '\n';
	}

    return 0;
}