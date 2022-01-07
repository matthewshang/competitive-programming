#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-01-06
 * Source: CSES
 * Summary: For how many each range contains, sort by ends and keep track of how
 * many begins are at least the current range's begin. Similarly for how many
 * contain each range, sort by begins and keep track of how many ends are at
 * least the current range's end. Both can be done with ordered set (although
 * it's really a multiset, just use pairs of {x, time}).
 */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct range {
    int s, e, id;

    bool operator <(const range& r) const {
        return s == r.s ? e > r.e : s < r.s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].e >> ranges[i].s;
        ranges[i].id = i;
    }

    for (int z = 0; z < 2; z++) {
        sort(ranges.begin(), ranges.end());

        vector<int> containing(n);
        ordered_set<pair<int, int>> seen;
        int t = 1;
        for (auto [_, start, id] : ranges) {
            containing[id] = (int)seen.size() - seen.order_of_key({start, 0});
            seen.insert({start, t++});
        }

        for (int count : containing) {
            cout << count << " ";
        }
        cout << '\n';

        for (int i = 0; i < n; i++) {
            swap(ranges[i].s, ranges[i].e);
        }
    }

    return 0;
}