#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const int n = 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // string s; cin >> s;
    array<array<bool, n>, n> vis;
    vector<string> paths;
    F0R(i, n) F0R(j, n) vis[i][j] = false;

    function<void(int, int, int, string&)> dfs = [&](int r, int c, int d, string& cur) {
        if (r < 0 || r >= n || c < 0 || c >= n || d >= n * n) return;
        if (vis[r][c]) return;

        if (r == n - 1 && c == n - 1 && d == n * n - 1) {
            paths.push_back(cur);
            // cout << cur << endl;
            return;
        }

        vis[r][c] = true;
        cur += 'U';
        dfs(r - 1, c, d + 1, cur);
        cur[d] = 'D';
        dfs(r + 1, c, d + 1, cur);
        cur[d] = 'L';
        dfs(r, c - 1, d + 1, cur);
        cur[d] = 'R';
        dfs(r, c + 1, d + 1, cur);
        cur.erase(d, 1);
        vis[r][c] = false;
    };

    string p = "";
    dfs(0, 0, 0, p);
    cout << paths.size() << endl;


    return 0;
}
