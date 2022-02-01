#include "bits/stdc++.h"
using namespace std;

/* Date: 2022-01-31
 * Source: UW 2022
 * Summary: Match pairs using a stack. Any remaining pairs must be formed at
 * the 'seam' of the circle.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        if (s.empty() || s.top() != a) {
            s.push(a);
        } else {
            s.pop();
        }
    }

    vector<int> leftover;
    while (!s.empty()) {
        leftover.push_back(s.top());
        s.pop();
    }

    const int remaining = leftover.size();
    int unpaired = remaining;
    for (int i = 0; i < remaining; i++) {
        if (leftover[i] != leftover[remaining - 1 - i]) {
            break;
        }
        unpaired -= 2;
    }
    cout << unpaired << '\n';

    return 0;
}