#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

using pli = pair<ll, int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vpi adj[n + 1];
    F0R (i, m) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<ll> dist(n + 1, 1e15);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        for (auto [x, w] : adj[u]) if (dist[x] > dist[u] + w) {
            dist[x] = dist[u] + w;
            pq.emplace(dist[x], x);
        }
    }

    FOR (i, 1, n) cout << dist[i] << " ";
    cout << endl;

    return 0;
}
