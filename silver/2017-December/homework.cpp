#include "bits/stdc++.h"

using namespace std;

#define MAX_QS 100000

int main() {
    ifstream in("homework.in");
    ofstream out("homework.out");

    int n;
    int scores[MAX_QS];
    int mins[MAX_QS];
    int res[MAX_QS];

    in >> n;
    for (int i = 0; i < n; i++) {
        in >> scores[i];
    }

    int total = scores[n - 1];
    int max_res = 0;
    mins[n - 1] = scores[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mins[i] = min(mins[i + 1], scores[i]);
        total += scores[i];
        res[i] = (total - mins[i]) / (n - i - 1);
        if (res[i] == 197) {
            cout << "total: " << total << ", n - i - 1: " << n - i - 1 << endl;
        }
        if (res[i] > max_res) max_res = res[i];
        // cout << mins[i] << ", ";
    }
    // cout << endl;

    for (int i = 1; i < n - 2; i++) {
        if (res[i] == max_res) {
            cout << "res[" << i << "]: " << res[i] << ", max: " << max_res << endl;
            out << i << endl;
        }
    }

    if (n == 3) {
        out << 1 << endl;
    }

    return 0;
}