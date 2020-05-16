#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

double state[301][301][301];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vi a(n);
    F0R (i, n) cin >> a[i];
    array<int, 3> count{0};
    F0R (i, n) if (a[i] < 3) count[a[i]]++;
    F0R (i, n + 1) F0R (j, n + 1) F0R (k, n + 1) state[i][j][k] = -1;

    state[n][0][0] = 0;
    queue<array<int, 3>> q;
    q.push({n, 0, 0});
    const int NXT[3][4] = {{-1, 1, 0, 0}, {0, -1, 1, 0}, {0, 0, -1, 1}};
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur == count) break;
        F0R (i, 3) {
            auto next = cur;
            F0R (j, 3) next[j] += NXT[i][j];
            if (next[0] < 0 || next[1] < 0 || next[2] < 0) continue;
            if (state[next[0]][next[1]][next[2]] != -1) continue;
            int n3 = n - next[0] - next[1] - next[2];

            double val = 1;
            F0R (j, 3) {
                if ((j < 2 && next[j + 1] == 0) || (j == 2 && n3 == 0)) continue;
                auto tmp = next;
                F0R (k, 3) tmp[k] -= NXT[j][k];
                if (tmp[0] < 0 || tmp[1] < 0 || tmp[2] < 0) continue;
                double look = state[tmp[0]][tmp[1]][tmp[2]];
                if (look != -1) {
                    double coeff = j == 2 ? n3 : next[j + 1];
                    val += look * coeff / n;
                }
            }
            state[next[0]][next[1]][next[2]] = val * ((double)n / (n - next[0]));
            q.push(next);
        }
    }
    cout << fixed << setprecision(9) << state[count[0]][count[1]][count[2]] << endl;

    return 0;
}
