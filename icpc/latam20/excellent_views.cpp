#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-02-22
 * Source: LATAM 2020
 * Summary: Instead of trying to figure out which buildings are worth going to
 * from each building, determine for each building which buildings consider it
 * worth. Process the buildings in decreasing height. If p is the current
 * position and l/r are the positions of the last buildings processed to the
 * left/right, p is worth to [(l+p)/2 + 1, (r+p+1)/2 - 1] (abs radius 
 * condition). Use set + prefix sums.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i].first;
        h[i].second = i;
    }

    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    vector<int> worth(n + 1);
    set<int> present;
    present.insert(-1);
    present.insert(n);

    for (auto [_, pos] : h) {
        auto it = present.upper_bound(pos);
        int lo = *prev(it);
        int hi = *it;

        if (lo != -1) {
            lo = (lo + pos) / 2 + 1;
        } else {
            lo = 0;
        }
        if (hi != n) {
            hi = (hi + pos + 1) / 2 - 1;
        } else {
            hi = n - 1;
        }

        worth[lo]++;
        worth[hi + 1]--;
        present.insert(pos);
    }

    for (int i = 0; i < n; i++) {
        worth[i + 1] += worth[i];
        cout << (worth[i] - 1) << " ";
    }
    cout << "\n";

    return 0;
}