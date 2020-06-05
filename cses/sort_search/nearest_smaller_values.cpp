#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vi x(n);
    F0R (i, n)
        cin >> x[i];
    
    vi ans(n, -1);
    stack<int> st;
    RFOR (i, n - 1, 0) {
        while (!st.empty() && x[i] < x[st.top()]) {
            ans[st.top()] = i + 1;
            st.pop();
        }
        if (ans[i] == -1)
            st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = 0;
        st.pop();
    }

    F0R (i, n)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
