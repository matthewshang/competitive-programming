#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

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
        forn(i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        forn(i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

const int MAXG = 200;
int n, k;
int grid[202][202];
int answer = 0;

int kadane(int arr[MAXG], int& lo, int& hi) {
    int sum = 0, max_sum = 0;
    hi = -1;

    int start = 0;
    forn (i, MAXG) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            start = i + 1;
        } else if (sum > max_sum) {
            max_sum = sum;
            lo = start;
            hi = i;
        }
    }

    if (hi != -1) return max_sum;
    else return -1;
}

void paint_rect() {
    int max_sum = 0;
    int tmp[MAXG], sum, start, finish;
    int f_left, f_right, f_top, f_bot;

    forn (left, MAXG) {
        forn (i, MAXG) tmp[i] = 0;
        fora (right, left, MAXG) {
            forn (i, MAXG) tmp[i] += grid[i][right];
            int sum = kadane(tmp, start, finish);
            if (sum > max_sum) {
                max_sum = sum;
                f_left = left;
                f_right = right;
                f_bot = start;
                f_top = finish;
            }
        }
    }

    if (max_sum <= 0) return;

    fora (r, f_bot, f_top + 1) {
        fora (c, f_left, f_right + 1) {
            grid[r][c] = 0;
        }
    }
    answer += max_sum;
}

int main() {
    io::setIO("paintbarn");
    cin >> n >> k;
    forn (i, MAXG) forn (j, MAXG) grid[i][j] = 0;
    forn (i, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fora (r, y1, y2) {
            fora (c, x1, x2) {
                grid[r][c]++;
            }
        }
    }
    forn (r, MAXG) {
        forn (c, MAXG) {
            if (grid[r][c] == k) grid[r][c] = -1, answer++;
            else if (grid[r][c] == k - 1) grid[r][c] = 1;
            else grid[r][c] = 0;
        }
    }

    forn (i, 2) paint_rect();

    // forn (i, 10) io::pr(grid[i], 10);
    cout << answer << endl;

    return 0;
}