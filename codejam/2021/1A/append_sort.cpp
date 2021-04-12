#include "bits/stdc++.h"
using namespace std;

int cost(string& a, string& b) {
    int n = a.size();
    int m = b.size();
    if (n < m) {
        return 0;
    }
    if (n == m) {
        if (a < b) {
            return 0;
        } else {
            b += '0';
            return 1;
        }
    }

    // n > m
    int i = 0;
    string pre;
    while (i < m && a[i] == b[i]) {
        i++;
    }

    if (i == m) {
        // try to add one
        vector<int> d;
        int j = i;
        while (j < n) {
            d.push_back(a[j] - '0');
            j++;
        }
        int carry = 0;
        d.back() += 1;
        for (int k = n - m - 1; k >= 0; k--) {
            d[k] += carry;
            if (d[k] > 9) {
                carry = d[k] / 10;
                d[k] %= 10;
            } else {
                carry = 0;
            }
        }

        if (carry == 0) {
            for (int k = 0; k < int(d.size()); k++) {
                b += '0' + d[k];
            }
            return d.size();
        } else {
            for (int k = 0; k <= int(d.size()); k++) {
                b += '0';
            }
            return d.size() + 1;
        }
    } else if (a[i] > b[i]) {
        // add zeros + 1
        while (b.size() <= a.size()) {
            b +=  '0';
        }
        return n - m + 1;
    } else {
        // add just enough zeroes
        while (b.size() < a.size()) {
            b += '0';
        }
        return n - m;
    }
}

void solve(int test_case) {
    int N; cin >> N;
    vector<string> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int ops = 0;
    for (int i = 0; i < N - 1; i++) {
        ops += cost(X[i], X[i + 1]);
    }
    cout << "Case #" << test_case << ": " << ops << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }
    
    return 0;
}