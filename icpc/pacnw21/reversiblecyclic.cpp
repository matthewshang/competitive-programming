#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 * Notes: Internally reversibly cyclic = prefix of some rotation. Try all
 * substrings and binary search on rotations in O(fast enough).
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<string> rotations;
    for (int i = 0; i < n; i++) {
        rotations.push_back(s);
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    sort(rotations.begin(), rotations.end());

    auto cmp = [&](int i, int j, int r) {
        const string& t = rotations[r];
        for (int k = 0; k < j - i + 1; k++) {
            if (s[i + k] < t[k]) return -1;
            if (s[i + k] > t[k]) return +1;
        }
        return 0;
    };

    auto check_substring = [&](int i, int j) {
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int res = cmp(i, j, mid);
            if (res == 0) {
                return true;
            } else if (res == -1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return cmp(i, j, low) == 0;
    };

    reverse(s.begin(), s.end());
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        for (int j = i; j < n && ok; j++) {
            ok &= check_substring(i, j);
        }
    }
    cout << ok << "\n";

    return 0;
}