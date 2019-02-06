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

set<int> graph[MAXN];
int parent[MAXN];
int dp[MAXN][3];

int main() {
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
    // forn (i, n) color[i] = 0;
    // forn (i, k) {
    //     int b, c;  in >> b >> c;
    //     color[b - 1] = c;
    // }

        
    ofstream out("barnpainting.out");
    return 0;
}