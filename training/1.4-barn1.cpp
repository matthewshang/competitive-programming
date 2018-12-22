/*
ID: mshang41
LANG: C++11
TASK: barn1
*/

#include "bits/stdc++.h"

using namespace std;

#define pii pair<int, int>

bool gap_sorter(const pii &lhs, const pii &rhs) {
    return lhs.second - lhs.first > rhs.second - rhs.first;
}

int main() {
    ifstream input("barn1.in");
    ofstream output("barn1.out");

    int M, S, C;
    input >> M >> S >> C;
    vector<int> cows;
    for (int i = 0; i < C; i++) {
        int n;
        input >> n;
        cows.push_back(n);
    }
    sort(cows.begin(), cows.end());

    vector<pair<int, int> > gaps;
    int last = 0;
    for (int c : cows) {
        if (c - last > 1) {
            gaps.push_back(make_pair(last + 1, c - 1));
        }
        last = c;
    }
    if (last != S) {
        gaps.push_back(make_pair(last + 1, S));
    }
    sort(gaps.begin(), gaps.end(), &gap_sorter);
    for (auto &p : gaps) {
        cout << "F: " << p.first << ", S: " << p.second << endl;
    }

    vector<bool> blocked(S, true);
    int i = 1;
    int j = 0;
    int min = 1;
    int max = S;
    while (i < M && j < gaps.size()) {
        pii &gap = gaps[j++];
        for (int k = gap.first; k <= gap.second; k++) {
            blocked[k - 1] = false;
        }
        if (gap.second == max) {
            max = gap.first - 1;
        } else if (gap.first == min) {
            min = gap.second + 1;
        } else {
            i++;
        }

        cout << "i: " << i << ", j: " << j << ", min: " << min << ", max: " << max << endl;
        for (bool b : blocked) {
            cout << b;
        }
        cout << endl;
    }

    while (j < gaps.size()) {
        pii &gap = gaps[j++];
        cout << gap.first << endl;
        if (gap.second == max) {
            for (int k = gap.first; k <= max; k++) {
                blocked[k - 1] = false;
            }
            max = gap.first - 1;
        } else if (gap.first == min) {
            for (int k = min; k <= gap.second; k++) {
                blocked[k - 1] = false;
            }
            min = gap.second + 1;
        }
    }

    int n = 0;
    for (bool b : blocked) {
        if (b) n++;
        cout << b;
    }
    output << n << endl;
    cout << endl;
    cout << n << endl;

    return 0;
}