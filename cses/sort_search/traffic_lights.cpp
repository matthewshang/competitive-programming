#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int x, n; cin >> x >> n;
    vector<int> p(n); F0R (i, n) cin >> p[i];

    map<int, int> len;
    map<int, int> st;
    len.insert({x, 1});
    st.insert({0, x});
    F0R (i, n) {
        auto it = st.upper_bound(-p[i]);
        len[it->second]--;
        if (len[it->second] == 0)
            len.erase(it->second);
        int b = it->second - p[i] - it->first;
        int a = p[i] + it->first;
        len[b]++;
        len[a]++;
        st.insert({-p[i], b});
        it->second = a;
        cout << len.rbegin()->first << " ";
    }
    cout << endl;

    return 0;
}
