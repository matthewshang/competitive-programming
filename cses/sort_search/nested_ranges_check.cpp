#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-01-05
 * Source: CSES
 * Summary: Sort range open/close events such that enclosed ranges open last
 * and close first. Keep track of which ranges are open and which have already
 * been marked as containing.
 */

struct event {
    int time, id, other;
    bool open;

    bool operator<(const event& o) const {
        if (time == o.time) {
            if (open == o.open) {
                return other > o.other;
            } else {
                return !open;
            }
        }
        return time < o.time;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<event> events;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        events.push_back({x, i, y, true});
        events.push_back({y, i, x, false});
    }
    sort(events.begin(), events.end());

    set<pair<int, int>> open_ranges;
    set<pair<int, int>> unmarked_ranges;
    vector<bool> containing(n);
    vector<bool> contained(n);
    for (const auto& e : events) {
        if (e.open) {
            open_ranges.insert({-e.time, e.id});
            unmarked_ranges.insert({-e.time, e.id});
        } else {
            auto it = unmarked_ranges.lower_bound({-e.other, 0});
            while (it != unmarked_ranges.end()) {
                if (it->second != e.id) {
                    containing[it->second] = true;
                }
                it = unmarked_ranges.erase(it);
            }

            open_ranges.erase({-e.other, e.id});
            if (open_ranges.lower_bound({-e.other, 0}) != open_ranges.end()) {
                contained[e.id] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << containing[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << contained[i] << ' ';
    }
    cout << '\n';

    return 0;
}