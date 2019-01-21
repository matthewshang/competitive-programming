#include "bits/stdc++.h"

using namespace std;

typedef pair<pair<int, int>, int> pii;

int n;
vector<pii> ranges;
vector<pair<int, int>> interval;

void merge_interval(pair<int, int> range) {
    int start = range.first;
    int end = range.second;
    // Check endpoint intersection
    if (end >= interval[0].first && end <= interval[0].second) {
        interval[0].first = start;
        return;
    } else if (start >= interval.back().first &&
               start <= interval.back().second) {
        interval.back().second = end;
        return;
    } else {
        for (int i = 0; i < interval.size() - 1; i++) {
            auto &p = interval[i];
            auto &q = interval[i + 1];
            if (start >= p.first && start <= p.second) {
                if (end >= q.first && end <= q.second) {
                    // Merge
                    p.second = q.second;
                    interval.erase(interval.begin() + i + 1);
                } else {
                    p.second = end;
                }
                return;
            } else if (end >= p.first && end <= p.second) {
                p.first = start;
                return;
            }
        }
    }
    // Disjoint intersection
    if (end < interval[0].first) {
        interval.insert(interval.begin(), range);
    } else if (start > interval.back().second) {
        interval.push_back(range);
    } else {
        for (int i = 0; i < interval.size() - 1; i++) {
            auto &p = interval[i];
            auto &q = interval[i + 1];
            if (start > p.second && start < q.first) {
                interval.insert(interval.begin() + i + 1, range);
                return;
            }
        }
    }
}

bool test(pair<int, int> range) {
    int start = range.first;
    int end = range.second;
    for (int i = 0; i < interval.size(); i++) {
        auto &p = interval[i];
        if (start >= p.first && start <= p.second && end >= p.first &&
            end <= p.second) {
            return false;
        }
    }
    merge_interval(range);
    return true;
}

int main() {
    ifstream in("mountains.in");
    in >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        in >> x >> y;
        ranges.push_back(make_pair(make_pair(x - y, x + y), 2 * y));
    }
    sort(ranges.begin(), ranges.end(), [](const pii &lhs, const pii &rhs) {
        // if (lhs.second > rhs.second) {
        //     return true;
        // } else {
        //     return lhs.first.first < rhs.first.first;
        // }
        if (lhs.second == rhs.second) 
            return lhs.first.first < rhs.first.first;
        return lhs.second > rhs.second;
    });
    interval.push_back(ranges[0].first);
    for (auto& r : ranges) {
        cout << "len: " << r.second << " s: " << r.first.first
             << " e: " << r.first.second << endl;
    }

    int visible = 1;
    for (int i = 1; i < ranges.size(); i++) {
        auto &r = ranges[i];
        if (test(r.first)) {
            cout << "visible" << endl;
            visible++;
        }
        cout << "len: " << r.second << " s: " << r.first.first
             << " e: " << r.first.second << endl;
        cout << "interval: ";
        for (auto &p : interval) {
            cout << "(" << p.first << ", " << p.second << "), ";
        }
        cout << endl;
    }

    cout << visible << endl;
    ofstream out("mountains.out");
    out << visible << endl;

    return 0;
}