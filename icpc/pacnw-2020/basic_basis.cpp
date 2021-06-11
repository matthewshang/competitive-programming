#include <bits/stdc++.h>
using namespace std;

// Build an XOR basis out of the b_i and save the original index of each
// basis vector. To answer a query, go through the insert vector step
// of building a basis but don't actually insert while keeping track of the
// highest index used. If at any point the LSB is 1 but there's nothing
// in the basis, the answer is -1. This works because we built the basis
// starting from b_1, so the basis always uses the leftmost possible vector
// which is what we want for a minimal prefix. There is an edge case for
// answering a 0 vector query. To answer this, keep track of the first vector
// that wasn't inserted into the basis. If it wasn't inserted, then every
// single bit it was active already had a vector, so using it would result
// in an XOR sum of 0 as desired.

constexpr int B = 160;
using vec = bitset<B>;

vec read_vec() {
    string s;
    cin >> s;
    vec v;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        int d;
        if ('0' <= c && c <= '9') {
            d = c - '0';
        } else {
            d = c - 'a' + 10;
        }
        for (int j = 0; j < 4; j++) {
            v.set(i * 4 + j, d & (1 << (3 - j)));
        }
    }
    return v;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vec> basis(B);
    vector<int> who(B);
    int first_excluded = -1;
    for (int i = 1; i <= n; i++) {
        vec v = read_vec();
        bool added = false;
        for (int j = 0; j < B; j++) {
            if (!v.test(j)) {
                continue;
            }
            if (who[j] == 0) {
                basis[j] = v;
                who[j] = i;
                added = true;
                break;
            }
            v ^= basis[j];
        }
        if (!added && first_excluded == -1) {
            first_excluded = i;
        }
    }    

    while (m--) {
        vec v = read_vec();
        if (v.none()) {
            cout << first_excluded << '\n';
            continue;
        }
        bool good = true;
        int ans = -1;
        for (int j = 0; j < B; j++) {
            if (!v.test(j)) {
                continue;
            }
            if (who[j] == 0) {
                good = false;
                break;
            }
            v ^= basis[j];
            ans = max(ans, who[j]);
        }

        cout << (good ? ans : -1) << '\n';
    }

    return 0;
}