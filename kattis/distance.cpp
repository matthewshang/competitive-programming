#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int64_t> s(N);
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> a[i];
    }

    sort(s.begin(), s.end());
    sort(a.begin(), a.end());
    int64_t sum = 0;
    int64_t s_so_far = 0;
    int64_t a_so_far = 0;
    for (int i = 0; i < N; i++) {
        sum += s[i] * i - s_so_far;
        sum += a[i] * i - a_so_far;
        s_so_far += s[i];
        a_so_far += a[i];
    }
    cout << sum << '\n';

    return 0;
}