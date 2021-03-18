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
    void setIO(string s) {
    }

    void pr(const vi &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

int factor(int n) {
    int x = 2;
    while (x * x <= n) {
        if (n % x == 0) return x;
        ++x;
    }
    return -1;
}

// string solve(int N, int L, int* ciph) {
//     vi primes(L + 1);
//     int p = factor(ciph[0]);
//     int q = ciph[0] / p;
//     F0R (i, L - 1) {
//         if (ciph[i + 1] % p == 0) {
//             primes[i + 1] = p;
//             if (i == 0) primes[i] = q;
//             q = ciph[i + 1] / p;
//         } else {
//             primes[i + 1] = q;
//             if (i == 0) primes[i] = p;
//             p = ciph[i + 1] / q;
//         }
//     }
//     primes[L] = ciph[L - 1] / primes[L - 1];

//     vi cpy = primes;
//     map<int, char> alpha;
//     sort(cpy.begin(), cpy.end());
//     char c = 'A';
//     for (int x : cpy) {
//         if (alpha.find(x) == alpha.end()) {
//             alpha[x] = c++;
//         }
//     }

//     string answer = "";
//     for (int x : primes) answer += alpha[x];
//     return answer;
// }

string solve(int N, int L, int* ciph) {
    vi primes;
    int p = factor(ciph[0]);
    int q = ciph[0] / p;
    F0R (i, L - 1) {
        if (ciph[i] == ciph[i + 1]) continue;
        if (ciph[i + 1] % p == 0) {
            if (primes.empty()) primes.push_back(q);
            primes.push_back(p);
            q = ciph[i + 1] / p;
        } else {
            if (primes.empty()) primes.push_back(p);
            primes.push_back(q);
            p = ciph[i + 1] / q;
        }
    }
    primes[L] = ciph[L - 1] / primes[L - 1];

    vi cpy = primes;
    map<int, char> alpha;
    sort(cpy.begin(), cpy.end());
    char c = 'A';
    for (int x : cpy) {
        if (alpha.find(x) == alpha.end()) {
            alpha[x] = c++;
        }
    }

    string answer = "";
    for (int x : primes) answer += alpha[x];
    return answer;
}

int main() {
    #ifdef TESTING
    freopen("crypto.in", "r", stdin);
    #endif

    int T; cin >> T;
    FOR (i, 1, T + 1) {
        int N, L; cin >> N >> L;
        int ciph[L];
        F0R (i, L) cin >> ciph[i];

        string S = solve(N, L, ciph);
        cout << "Case #" << i << ": " << S << endl;
    }
    return 0;
}
