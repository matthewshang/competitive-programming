#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int N;
        cin >> N;
        vector<int> C(N + 1);
        for (int v = 1; v <= N; v++) {
            cin >> C[v];
        }

        vector<vector<int>> g(N + 1);
        for (int e = 0; e < N - 1; e++) {
            int A, B;
            cin >> A >> B;
            g[A].push_back(B);
            g[B].push_back(A);
        }

        function<int(int, int)> get_max_sum = [&](int v, int p) -> int {
            int max_sum = C[v];
            for (int to : g[v]) {
                if (to != p) {
                    max_sum = max(max_sum, C[v] + get_max_sum(to, v));
                }
            }
            return max_sum;
        };

        vector<int> children;
        for (int to : g[1]) {
            children.push_back(get_max_sum(to, 1));
        }

        int ore = C[1];
        if (children.size() == 1) {
            ore += children[0];
        } else if (children.size() >= 2) {
            sort(children.begin(), children.end(), greater<int>());
            ore += children[0] + children[1];
        }
        cout << "Case #" << test_case << ": " << ore << '\n';
    }

    return 0;
}