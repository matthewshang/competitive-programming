#include <bits/stdc++.h>
using namespace std;

constexpr int K = 2;
const array<int64_t, K> P = {5, 11};
const array<int64_t, K> M = {int(1e9) + 7, int(1e9) + 9};
using Hash = array<int64_t, K>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	array<string, 3> ss;
	for (int i = 0; i < 3; i++) {
		cin >> ss[i];
	}
	
	const int n = ss[0].size();
	auto calc = [&](const string& fixed, const string& vary, const string& last) -> int {
		map<Hash, int> dist;
		for (int rot = 0; rot < n; rot++) {
			Hash h{}, p{};
			fill(p.begin(), p.end(), 1);
			for (int i = 0; i < n; i++) {
				int d = last[(rot + i) % n] - 'A';
				for (int k = 0; k < K; k++) {
					h[k] = (h[k] + (d + 1) * p[k] % M[k]) % M[k];
					p[k] = p[k] * P[k] % M[k];
				}
			}
			if (auto it = dist.find(h); it == dist.end()) {
				dist[h] = rot;
			} else {
				dist[h] = min(dist[h], min(rot, n - rot));
			}
		}
		
		int best = 1e9;
		for (int rot = 0; rot < n; rot++) {
			Hash h{}, p{};
			fill(p.begin(), p.end(), 1);
			bool ok = true;
			for (int i = 0; i < n; i++) {
				int df = fixed[i] - 'A';
				int dv = vary[(rot + i) % n] - 'A';
				if (df == dv) {
					ok = false;
					break;
				}
				
				int d;
				if ((df == 0 && dv == 1) || (df == 1 && dv == 0)) {
					d = 2;
				} else if ((df == 0 && dv == 2) || (df == 2 && dv == 0)) {
					d = 1;
				} else {
					d = 0;
				}
				
				for (int k = 0; k < K; k++) {
					h[k] = (h[k] + (d + 1) * p[k] % M[k]) % M[k];
					p[k] = p[k] * P[k] % M[k];
				}
			}
			
			if (ok) {
				if (auto it = dist.find(h); it != dist.end()) {
					int q = min(rot, n - rot) + min(it->second, n - it->second);
					best = min(best, q);
				}
			}
		}
		return best;
	};
	
	int ans = 1e9;
	ans = min(ans, calc(ss[0], ss[1], ss[2]));
	ans = min(ans, calc(ss[0], ss[2], ss[1]));
	ans = min(ans, calc(ss[1], ss[0], ss[2]));
	ans = min(ans, calc(ss[1], ss[2], ss[0]));
	ans = min(ans, calc(ss[2], ss[0], ss[1]));
	ans = min(ans, calc(ss[2], ss[1], ss[0]));
	cout << (ans == 1e9 ? -1 : ans) << '\n';
	
	return 0;
}
