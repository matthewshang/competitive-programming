#include <bits/stdc++.h>
using namespace std;

// For each board, how wide can we make a rectangle if we use the board as
// the height? We keep a monotonically increasing stack of heights. When
// we have to pop a height off, the first height to the right that's too small
// is the current, and the first to the left is the previous in the stack.
// After going through all the boards, we know every height left in the stack
// can be extended all the way to the right and to the previous in the stack.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int64_t max_area = 0;
    vector<int> st;
    st.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (h[st.back()] >= h[i]) {
            int rem = st.back();
            st.pop_back();
            max_area = max(max_area, h[rem] * int64_t(i - st.back() - 1));
        }
        st.push_back(i);
    }
    while (st.size() > 1) {
        int rem = st.back();
        st.pop_back();
        max_area = max(max_area, h[rem] * int64_t(n - st.back()));
    }
    cout << max_area << '\n';

    return 0;
}
