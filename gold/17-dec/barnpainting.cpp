#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

namespace io {
void pr(const vi &v) {
    forn(i, v.size()) cout << v[i] << " ";
    cout << endl;
}

template <typename T> void pr(T *arr, int n) {
    forn(i, n) cout << arr[i] << " ";
    cout << endl;
}
} // namespace io

const int MAXN = 10000;
const ll MOD = 1000000007;

int main() {
    set<int> graph[MAXN];
    int parent[MAXN];
    ll dp[MAXN][3];
    int mark[MAXN];
    bool fixed[MAXN];
    int n, k;

    ifstream in("barnpainting.in");
    in >> n >> k;
    forn (i, n) parent[i] = -1;
    forn (i, n - 1) {
        int x, y;
        in >> x >> y;
        x--;
        y--;
        if (parent[x] == -1) {
            graph[y].insert(x);
            parent[x] = y;
        } else if (parent[y] == -1) {
            graph[x].insert(y);
            parent[y] = x;
        } else {
            parent[parent[x]] = x;
            graph[parent[x]].erase(x);
            parent[x] = y;
            graph[y].insert(x);
        }
    }

    forn (i, n) {
        forn (j, 3) dp[i][j] = 0;
        fixed[i] = false;
    }
    forn (i, k) {
        int b, c;  in >> b >> c;
        dp[b - 1][c - 1] = 1;
        fixed[b - 1] = true;
    }
    forn (i, n) {
        cout << "node " << i << ": parent: " << parent[i] << endl;
        for (int x : graph[i]) {
            cout << x << " ";
        }
        cout << endl;
        cout << "dp: " << dp[i][0] << ", " << dp[i][1] << ", " << dp[i][2] << endl;
    }

    queue<int> q;
    ll answer = 1;
    int root = -1;
    forn (i, n) {
        mark[i] = graph[i].size();
        if (mark[i] == 0) {
            q.push(i);
            cout << "leaf: " << i << endl;
        }
        if (parent[i] == -1) root = i;
    }
    cout << "root: " << root << endl;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (mark[u] == -1) {
            continue;
        } else if (mark[u] != 0) {
            q.push(u);
            continue;
        }

        for (int x : graph[u]) {
            dp[u][0] = dp[u][0] * (dp[x][1] + dp[x][2]);
            dp[u][1] = dp[u][1] * (dp[x][0] + dp[x][2]);
            dp[u][2] = dp[u][2] * (dp[x][0] + dp[x][1]);
        }
        if (fixed[u]) {
            answer *= dp[u][0] + dp[u][1] + dp[u][2];
        }
        if (graph[u].size() == 0) {
            forn (i, 3) dp[u][i] = 1;
        }
        
        if (parent[u] != -1) {
            mark[parent[u]]--;
            q.push(parent[u]);
        }
    }

    if (!fixed[root]) {
        for (int x : graph[root]) {
            dp[root][0] = dp[root][0] * (dp[x][1] + dp[x][2]);
            dp[root][1] = dp[root][1] * (dp[x][0] + dp[x][2]);
            dp[root][2] = dp[root][2] * (dp[x][0] + dp[x][1]);
        }
        answer *= dp[root][0] + dp[root][1] + dp[root][2];
    }


        
    cout << answer << endl;
    ofstream out("barnpainting.out");
    return 0;
}