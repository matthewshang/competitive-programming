#include <bits/stdc++.h>
using namespace std;

// The solution is similar to induction. Suppose after examining i-1 iterations
// of the sorted array, the smallest nonrepresentable integer is x (in other
// words, all sums from 1 to x-1 have a corresponding subset using the first
// i-1 items). Then if a[i] > x, x must be the answer since adding a[i] to any
// previous subset results in a sum greater than x. Otherwise, we now have
// subsets for 1 to x-1+a[i] by adding a[i] to a previous subset.

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

    int64_t ans = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] > ans) break;
        ans += x[i];
    }
    cout << ans << '\n';

    return 0;
}
