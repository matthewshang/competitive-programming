#include "bits/stdc++.h"
using namespace std;

int query(int i, int j, int k) {
    cout << i << ' ' << j << ' ' << k << endl;
    int L; cin >> L;
    if (L == -1) {
        exit(0);
    }
    return L;
}

bool answer(vector<int>& a) {
    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;
    int res; cin >> res;
    return res == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, Q; cin >> T >> N >> Q;
    for (int tc = 1; tc <= T; tc++) {
        vector<int> ord{1, 2};
        int who = query(1, 2, 3);
        if (who == 1) {
            ord.insert(ord.begin(), 3);
        } else if (who == 2) {
            ord.push_back(3);
        } else {
            ord.insert(ord.begin() + 1, 3);
        }

        auto check_edges = [&](int i) -> bool {
            int who = query(ord.front(), ord.back(), i);
            if (who == ord.front()) {
                ord.insert(ord.begin(), i);
                return true;
            } else if (who == ord.back()) {
                ord.push_back(i);
                return true;
            }
            return false;
        };

        for (int i = 4; i <= N; i++) {
            int low = 0;
            int high = ord.size() - 1;
            bool first = true;
            bool add = true;
            while (high - low > 1) {
                int mid1 = (2 * low + high) / 3;
                int mid2 = (low + 2 * high) / 3;

                int who = query(ord[mid1], ord[mid2], i);
                if (who == i) {
                    low = mid1;
                    high = mid2;
                } else if (who == ord[mid2]) {
                    low = mid2;
                    if (first) {
                        if (check_edges(i)) {
                            add = false;
                            break;
                        }
                    }
                } else {
                    high = mid1;
                    if (first) {
                        if (check_edges(i)) {
                            add = false;
                            break;
                        }
                    }
                }

                if (first) {
                    first = false;
                }
            }

            if (add) {
                ord.insert(ord.begin() + low + 1, i);
            }
        }

        if (!answer(ord)) {
            return 0;
        }
    }

    return 0;
}