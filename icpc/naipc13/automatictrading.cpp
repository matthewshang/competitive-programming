#include <bits/stdc++.h>
using namespace std;

/* Binary search on hashes of substrings. */

using Hash = array<int64_t, 2>;
constexpr Hash P = {53, 59};
constexpr Hash M = {int(1e9) + 7, int(1e9) + 9};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<Hash> h(n + 1);
    vector<Hash> p(n + 1);
    p[0][0] = p[0][1] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        if (islower(s[i])) {
            a = s[i] - 'a' + 1;
        } else {
            a = s[i] - 'A' + 27;
        }
        for (int k = 0; k < 2; k++) {
            h[i + 1][k] = (h[i][k] + a * p[i][k] % M[k]) % M[k];
            p[i + 1][k] = p[i][k] * P[k] % M[k];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        int lo = 0;
        int hi = n - b;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (mid == 0) {
                break;
            }

            Hash ha = h[a + mid];  // hash(s[a..a+mid-1]) * p^a
            Hash hb = h[b + mid];  // hash(s[b..b+mid-1]) * p^b
            for (int k = 0; k < 2; k++) {
                ha[k] = (ha[k] - h[a][k] + M[k]) % M[k];
                hb[k] = (hb[k] - h[b][k] + M[k]) % M[k];
                ha[k] = ha[k] * p[b - a][k] % M[k];
            }

            if (ha == hb) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << '\n';
    }

    return 0;
}