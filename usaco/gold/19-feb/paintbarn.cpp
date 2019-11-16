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
    void setIO(string s) {
        freopen((s + ".in").c_str(), "r", stdin);
        #ifndef TESTING
        freopen((s + ".out").c_str(), "w", stdout);
        #endif
    }

    void pr(const vi &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}


int kadane(int* arr, int sz) {
    int sum = 0, max_sum = 0, hi = -1;

    F0R (i, sz) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
        } else if (sum > max_sum) {
            max_sum = sum;
            hi = i;
        }
    }

    if (hi != -1) return max_sum;
    else return -1;
}

int main() {
    io::setIO("paintbarn");

    int n, k;
    // N: maximum coordinate
    int N = 0;
    int grid[202][202];
    cin >> n >> k;
    F0R (i, 202) F0R (j, 202) grid[i][j] = 0;
    F0R (i, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        N = max(N, max(x2, y2));
        FOR (r, y1, y2) {
            FOR (c, x1, x2) {
                grid[r][c]++;
            }
        }
    }

    // set grid to -1, 1, or 0 based on contribution and get current K-coated area
    int existing_sum = 0;
    F0R (r, N) {
        F0R (c, N) {
            if (grid[r][c] == k) grid[r][c] = -1, existing_sum++;
            else if (grid[r][c] == k - 1) grid[r][c] = 1;
            else grid[r][c] = 0;
        }
    }

    const int M = N + 1;
    int mt[M], mb[M], mr[M], ml[M], tmp[N];
    F0R (i, M) mt[i] = mb[i] = mr[i] = ml[i] = 0;
    F0R (line, N) {
        F0R (i, N) tmp[i] = 0;
        // max sum between every pair of vertical lines 
        FOR (end, line, N) {
            F0R (i, N) tmp[i] += grid[i][end];
            int sum = kadane(tmp, N);
            mr[line] = max(mr[line], sum);
            ml[end + 1] = max(ml[end + 1], sum);
        }

        F0R (i, N) tmp[i] = 0;
        // max sum between every pair of horizontal lines 
        FOR (end, line, N) {
            F0R (i, N) tmp[i] += grid[end][i];
            int sum = kadane(tmp, N);
            mt[line] = max(mt[line], sum);
            mb[end + 1] = max(mb[end + 1], sum);
        }
    }
    F0R (i, M) {
        ml[i + 1] = max(ml[i + 1], ml[i]);  
        mb[i + 1] = max(mb[i + 1], mb[i]);
    }
    F0Rd (i, N - 1) {
        mr[i] = max(mr[i], mr[i + 1]);
        mt[i] = max(mt[i], mt[i + 1]);
    }

    int max_sum = 0;
    F0R (i, N) {
        max_sum = max(max_sum, ml[i] + mr[i]);
        max_sum = max(max_sum, mb[i] + mt[i]);
    }

    cout << existing_sum + max_sum << endl;

    return 0;
}
