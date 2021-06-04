#include <bits/stdc++.h>
using namespace std;

// We observe that a triangular subset is completely determined by the first
// two elements: as long as a_1 + a_2 > a_k for all 3 <= k <= n (where n is
// the size of the subset), then the triangle property will hold. We fix
// a_1 and a_2 and count the possible a_k's, adding 2^count-1 to the answer.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    int64_t subsets = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int k = j + 1;
            if (x[k] < x[i] + x[j]) {
                int count = 0;
                while (k < n && x[k] < x[i] + x[j]) {
                    count++;
                    k++;
                }
                subsets += (1LL << count) - 1;
            }
        }
    }
    cout << subsets << '\n';

    return 0;
}