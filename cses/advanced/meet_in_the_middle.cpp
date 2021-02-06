#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long x; cin >> x;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<long long> a;
    for (int mask = 0; mask < (1 << (n / 2)); mask++) {
        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            if (mask & (1 << i)) {
                sum += t[i];
            }
        }
        a.push_back(sum);
    }

    vector<long long> b;
    int m = (n + 1) / 2;
    for (int mask = 0; mask < (1 << m); mask++) {
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                sum += t[n / 2 + i];
            }
        }
        b.push_back(sum);
    }

    auto gen = [&](vector<long long>& v) -> vector<pair<long long, int>> {
        sort(v.begin(), v.end());
        vector<pair<long long, int>> cmp;
        for (int i = 0; i < (int)v.size(); ) {
            int j = i;
            int count = 0;
            while (j < (int)v.size() && v[j] == v[i]) {
                count++;
                j++;
            }
            cmp.push_back({ v[i], count });
            i = j;
        }
        return cmp;
    };

    auto cmp_a = gen(a);
    auto cmp_b = gen(b);
    long long ways = 0;
    int i = 0, j = (int)cmp_b.size() - 1;
    while (i < (int)cmp_a.size() && j >= 0) {
        long long cur = cmp_a[i].first + cmp_b[j].first;
        if (cur == x) {
            ways += (long long)cmp_a[i].second * cmp_b[j].second;
            j--;
        } else if (cur < x) {
            i++;
        } else {
            j--;
        }
    }
    cout << ways << '\n';

    return 0;
}