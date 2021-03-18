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

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int b;

int query(int pos) {
    cout << (pos + 1) << endl;
    int res; cin >> res;
    return res;
}

bool answer(vector<int>& ans) {
    F0R (i, b) cout << ans[i];
    cout << endl;
    char res; cin >> res;
    return res == 'Y';
}

bool solve() {
    vector<int> s(b, 0);
    int same = -1, diff = -1;
    F0R (i, 5) {
        s[i] = query(i);
        s[b - 1 - i] = query(b - 1 - i);
        if (s[i] == s[b - 1 - i]) {
            same = i;
        } else {
            diff = i;
        }
    }
    if (b == 10) {
        return answer(s);
    }

    auto flip = [&]() {
        F0R (i, b) s[i] = 1 - s[i];
    };
    auto rev = [&]() {
        reverse(all(s));
    };

    int rep = (b - 10) / 8 + 1;
    F0R (i, rep) {
        if (same == -1) {
            int res = query(diff);
            if (res != s[diff]) flip();
            query(0);
        } else if (diff == -1) {
            int res = query(same);
            if (res != s[same]) flip();
            query(0);
        } else {
            int r1 = query(same), r2 = query(diff);
            if (r1 != s[same] && r2 != s[diff]) {
                flip();
            } else if (r1 == s[same] && r2 != s[diff]) {
                rev();
            } else if (r1 != s[same] && r2 == s[diff]) {
                flip(); rev();
            }
        }
        F0R (j, 4) {
            int l = 5 + i * 4 + j;
            
            s[l] = query(l);
            s[b - 1 - l] = query(b - 1 - l);
            if (s[l] == s[b - 1 - l]) {
                if (same == -1) same = l;
            } else {
                if (diff == -1) diff = l;
            }
            if (l >= b / 2) break;
        }
    }
    return answer(s);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t >> b;
    FOR (i, 1, t) {
        if (!solve()) {
            return 0;
        }
    }

    return 0;
}
