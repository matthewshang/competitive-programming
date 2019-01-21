#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pi;

int n;
vector<pi> ranges;

bool contains(pi &r, pi &test) {
    return test.first >= r.first && test.first <= r.second &&
           test.second >= r.first && test.second <= r.second;
}

bool test(pi &r, int i) {
    // int j = i - 1;
    // while (j >= 0 && ranges[j].second > r.first) {
    //     if (contains(ranges[j], r)) {
    //         return false;
    //     }
    //     j--;
    // }
    // j = i + 1;
    // while (j < n && ranges[j].first < r.second) {
    //     if (contains(ranges[j], r)) {
    //         return false;
    //     }
    //     j++;
    // }
    // return true;
    for (int j = 0; j < ranges.size(); j++) {
        if (i == j) continue;

        if (contains(ranges[j], r)) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream in("mountains.in");
    in >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        in >> x >> y;
        ranges.push_back(make_pair(x - y, x + y));
    }
    sort(ranges.begin(), ranges.end(), [](const pi &lhs, const pi &rhs) {
        // if (lhs.second > rhs.second) {
        //     return true;
        // } else {
        //     return lhs.first.first < rhs.first.first;
        // }
        if (lhs.first == rhs.first)
            return lhs.second - lhs.first < rhs.second - rhs.first;
        return lhs.first < rhs.first;
    });

    // for (auto &r : ranges) {
    //     cout << "len: " << r.second - r.first << " s: " << r.first
    //          << " e: " << r.second << endl;
    // }

    int visible = 0;
    for (int i = 0; i < ranges.size(); i++) {
        auto &r = ranges[i];
        if (test(r, i)) {
            visible++;
        }
    }

    // cout << visible << endl;
    ofstream out("mountains.out");
    out << visible << endl;

    return 0;
}