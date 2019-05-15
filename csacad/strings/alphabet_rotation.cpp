#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define F0R(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define F0Rd(i, a) for (int i = (a); i >= 0; --i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

namespace io {
    template <typename T> void pr(const vector<T> &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

string rot(string& s, int offset) {
    string cpy = s;
    F0R (i, s.size()) cpy[i] = 'a' + (s[i] - 'a' + offset) % 26;
    return cpy;
}

int main() {
    int N; cin >> N;
    vector<string> strings(N); F0R (i, N) cin >> strings[i];

    unordered_map<string, int> mp;
    for (string& s : strings) {
        int off = 26 - s[0] - 'a';
        s = rot(s, off);
        mp[s] += 1;
    }

    for (string& s : strings) {
        int off = 26 - s[0] - 'a';
        bool res = mp[rot(s, off)] > 1;
        cout << res << endl;
    }
    
    return 0;
}
