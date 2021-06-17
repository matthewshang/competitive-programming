#include <bits/stdc++.h>
using namespace std;

// Use an ordered_set to keep track of who's left. Once we remove the person
// at pos in the set, the next person to be removed is at
// (pos + k) % (people left). We only add k because someone else has already
// taken the seat at position pos.

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    ordered_set<int> alive;
    for (int i = 1; i <= n; i++) {
        alive.insert(i);
    }

    int pos = 0;
    for (int i = 1; i <= n; i++) {
        pos = (pos + k) % alive.size();
        auto it = alive.find_by_order(pos);
        cout << *it << " ";
        alive.erase(it);
    }
    cout << '\n';

    return 0;
}
