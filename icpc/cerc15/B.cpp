#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    vector<int> w;
    int z = s.size();
    for (int i = 0; i < z;) {
        int j = i;
        while (j < z && s[j] != ' ') {
            j++;
        }
        w.push_back(j - i);
        i = j + 1;
    }
    int n = w.size();

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + w[i - 1];
    }

    auto len = [&](int start, int end) -> int {
        return pre[end + 1] - pre[start] + end - start;
    };

    int a, b;
    cin >> a >> b;
    for (int mx = a; mx <= b; mx++) {
        int tot = 0;
        int cur = 0;
        int num_words = 0;
        while (cur < n) {
            tot += w[cur];
            num_words++;
            if (len(cur, n - 1) <= mx) break;

            int lo = cur + 1;
            int hi = n - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (len(cur, mid) > mx) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            cur = lo;
        }
        tot += num_words - 1;
        cout << tot << '\n';
    }

    return 0;
}