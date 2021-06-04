#include <bits/stdc++.h>
using namespace std;

int N;

int ask(int i, int j) {
    cout << "M " << i << ' ' << j << endl;
    int pos;
    cin >> pos;
    if (pos == -1) {
        exit(EXIT_FAILURE);
    }
    return pos;
}

void ask_swap(int i, int j) {
    cout << "S " << i << ' ' << j << endl;
    int res;
    cin >> res;
    if (res == -1) {
        exit(EXIT_FAILURE);
    }
}

void finish() {
    cout << 'D' << endl;
    int res;
    cin >> res;
    if (res == -1) {
        exit(EXIT_FAILURE);
    }
}

void solve(int test_case) {
    for (int i = 1; i < N; i++) {
        int pos = ask(i, N);
        if (pos != i) {
            ask_swap(i, pos);
        }
    }
    finish();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T >> N;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}