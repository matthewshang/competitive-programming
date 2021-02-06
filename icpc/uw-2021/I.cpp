#include "bits/stdc++.h"
using namespace std;

struct BIT { // Operation must be reversible
    vector<int> bit;
    BIT(int n) : bit(n + 1) {}
    int query(int pos) {
        int ans = 0;
        for (pos++; pos > 0; pos -= pos & -pos) ans += bit[pos];
        return ans;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int pos, int delta) {
        for (pos++; pos < int(bit.size()); pos += pos & -pos) bit[pos] += delta;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int p, a; cin >> p >> a;

    auto modpow = [&](int A, int B) -> int {
        int x = 1, y = A;
        while (B) {
            if (B % 2) x = (long long)x * y % p;
            y = (long long)y * y % p;
            B /= 2;
        }
        return x;
    };

    int g = (p - 1) / a;
    int ainv = modpow(a, p - 2);
    vector<pair<int, int>> ord;
    for (int i = 1; i <= a; i++) {
        int j = (long long)i * ainv % p;
        ord.push_back({ j, i });
    }
    sort(ord.begin(), ord.end());

    BIT more(a + 1);
    BIT spec(a + 1);
    int total_spec = 0;
    long long res = 0;
    for (int i = 0; i < a; i++) {
        int ii = ord[i].second;
        long long above = more.query(ii, a);
        long long below = i - above;
        res += above * g * (g + 1) / 2;
        res += total_spec * g;
        res += below * g * (g - 1) / 2;

        more.update(ii, 1);
        int len = (p - ii - 1) / a + 1;
        if (len > g) {
            long long above_spec = spec.query(ii, a);
            res += above_spec;

            spec.update(ii, 1);
            total_spec++;
        }
    }
    cout << res << '\n';

    return 0;
}
