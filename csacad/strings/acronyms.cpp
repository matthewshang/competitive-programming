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

bool ok(string& str, int letters[26]) {
    int cpy[26]; F0R (i, 26) cpy[i] = letters[i];
    cpy[str[0] - 'a']--;
    F0R (i, str.size()) {
        int j = str[i] - 'a';
        if (--cpy[j] < 0) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    vector<string> s(N); F0R (i, N) cin >> s[i];
    
    int letters[26]; F0R (i, 26) letters[i] = 0;
    F0R (i, N) letters[s[i][0] - 'a']++;

    int answer = 0;
    for (auto& str : s) {
        if (ok(str, letters)) ++answer;
    }
    cout << answer << endl;
    return 0;
}
