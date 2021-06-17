#include <bits/stdc++.h>
using namespace std;

// Two pointers.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    map<int, int> count;
    int64_t ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        count[x[i]]++;
        while ((int)count.size() > k) {
            auto it = count.find(x[l]);
            if (--it->second == 0) {
                count.erase(it);
            }
            l++;
        }
        if ((int)count.size() <= k) {
            ans += i - l + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}