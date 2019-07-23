#include "bits/stdc++.h"

using namespace std;

using ll = long long;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int i = 3;
    while (i * i <= n) {
        if (n % i == 0) return false;
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    bool prime[1100];
    vector<pair<int, int>> edges;
    int n; cin >> n;
    for (int i = 1; i <= 1010; i++) prime[i] = is_prime(i);

    for (int i = 0; i < n - 1; i++) {
        edges.emplace_back(1 + i, 1 + i + 1);
    }
    edges.emplace_back(1 + n - 1, 1);

    if (!prime[n]) {
        int e = n;
        while (!prime[e]) e++;
        for (int i = 0; i < e - n; i++) {
            edges.emplace_back(1 + i, n / 2 + 1 + i);
        }
    }

    cout << edges.size() << endl;
    for (auto& e : edges) cout << e.first << " " << e.second << endl;

    return 0;
}
