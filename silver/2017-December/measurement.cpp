#include "bits/stdc++.h"

using namespace std;

int main() {
    ifstream in("measurement.in");
    ofstream out("measurement.out");

    int n, g;
    vector<array<int, 3>> log;
    in >> n >> g;
    for (int i = 0; i < n; i++) {
        int day, id, ch;
        in >> day >> id >> ch;
        log.push_back({day, id, ch});
    }
    sort(log.begin(), log.end());

    // for (auto& a : log) {
    //     cout << "day: " << a[0] << " id: " << a[1] << " +-: " << a[2] <<
    //     endl;
    // }
    map<int, int> cows;
    int max = g, old_max = max;
    int n_max = n;
    int changes = 0;
    for (auto& d : log) {
        map<int, int> copy = cows;
        int id = d[1], delta = d[2], old_n_max = n_max; 
        auto it = cows.find(id);
        if (it == cows.end()) {
            cows[id] = g + delta;
        } else {
            cows[id] += delta;
        }

        if (cows[id] > max) {
            n_max = 1;
            max = cows[id];
        } else if (cows[id] == max) {
            n_max++;
        } else {
            n_max--;
            if (n_max == 0) {
                max = 0;
                for (auto& c : cows) {
                    if (c.second > max) max = c.second;
                }
                if (g > max) max = g;
                for (auto& c : cows) {
                    if (c.second == max) n_max++;
                }
                if (max == g) n_max = n - n_max;
            }
        }

        if (old_n_max != n_max) {
            changes++;
        } else {
            for (auto& c : copy) {
                if (c.second == old_max && c.second != max) {
                    changes++;
                }
            }
        }

        // for (auto& c : cows) {
        //     cout << "id: " << c.first << " val: " << c.second << endl;
        // }
        // cout << "max: " << max << " n_max: " << n_max << endl;
        // cout << endl;

        old_max = max;
    }

    // cout << changes << endl;
    out << changes << endl;

    return 0;
}