#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define F0R(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define F0Rd(i, a) for (int i = (a); i >= 0; --i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

namespace io {
    void pr(const vi &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

int compress(int x, int y, int n) {
    return x * n + y;
}

// string solve(int N, string P) {
//     set<pair<int, int>> used;
//     int x = 0, y = N - 1;
//     F0R (i, 2 * N - 2) {
//         int x0 = x, y0 = y;
//         if (P[i] == 'E') x++;
//         else y--;
//         used.emplace(compress(x0, y0, N), compress(x, y, N));
//     }

//     queue<pair<pii, string>> q;
//     q.push(make_pair(make_pair(0, N - 1), ""));
//     while (!q.empty()) {
//         auto p = q.front();
//         q.pop();

//         int x = p.fi.fi, y = p.fi.se;
//         if (x == N - 1 && y == 0) return p.se;
//         if (x + 1 < N) {
//             auto it = used.find(make_pair(compress(x, y, N), compress(x + 1, y, N)));
//             if (it == used.end()) {
//                 q.push(make_pair(make_pair(x + 1, y), p.se + "E"));
//             }
//         }
//         if (y - 1 >= 0) {
//             auto it = used.find(make_pair(compress(x, y, N), compress(x, y - 1, N)));
//             if (it == used.end()) {
//                 q.push(make_pair(make_pair(x, y - 1), p.se + "S"));
//             }
//         }
//     }
//     return "";
// }

string solve(int N, string P) {
    // set<pair<int, int>> used;
    // int x = 0, y = N - 1;
    // F0R (i, 2 * N - 2) {
    //     int x0 = x, y0 = y;
    //     if (P[i] == 'E') x++;
    //     else y--;
    //     used.emplace(compress(x0, y0, N), compress(x, y, N));
    // }

    // string S = "";
    // dfs(0, N - 1, N, used, S);
    // reverse(S.begin(), S.end());
    string S = "";
    F0R (i, P.length()) {
        if (P[i] == 'E') S += 'S';
        else S += 'E';
    }
    return S;
}

int main() {
    int T; cin >> T;
    F0R (i, T) {
        int N; cin >> N;
        string P; cin >> P;
        
        string S = solve(N, P);
        cout << "Case #" << i + 1 << ": " << S << endl;
    }
    return 0;
}
