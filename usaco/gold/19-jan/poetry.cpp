#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

namespace io {
    template <typename T>
    void pr(const vector<T>& v) {
        forn (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T>
    void pr(T* arr, int n) {
        forn (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

const ll MOD = 1000000007;
const int MAXN = 5000;
const int MAXK = 5000;
int wordlens[MAXK + 1]; 
vi classes[MAXN];
int rhyme[26];

ll dp[MAXK + 1];

ll mod_exp(ll x, int n) {
    if (n == 0) return 1;
    int i = 1;
    ll base = x;
    while (i * 2 < n) {
        i *= 2;
        x = (x * x + MOD) % MOD;
    }

    while (i < n) {
        x = (x * base + MOD) % MOD;
        i++;
    }
    return x;
}

int main() {
    int n, m, k;
    ifstream in("poetry.in");
    in >> n >> m >> k;
    forn (i, n) wordlens[i] = 0;
    forn (i, n) {
        int s, c;  in >> s >> c;
        wordlens[s]++;
        classes[c - 1].push_back(s);
    }
    forn (i, 26) rhyme[i] = 0;
    forn (i, m) {
        char c;  in >> c;
        rhyme[c - 'A']++;
    }

    forn (i, k + 1) dp[i] = 0;
    dp[0] = 1;
    fora (i, 1, k + 1) {
        forn (j, i) {
            dp[i] = (dp[i] + ((ll)wordlens[i - j] * dp[j] + MOD) % MOD + MOD) % MOD;
        }
    }
    // dp[0] = 0;

    vector<ll> r;
    forn (i, MAXN) {
        if (!classes[i].empty()) {
            r.push_back(0);
            for (auto x : classes[i]) {
                r.back() = (r.back() + dp[k - x] + MOD) % MOD;
            }
        }
    }

    ll prod = 1;
    vector<ll> rexp = r;
    sort(rhyme, rhyme + 26);
    // io::pr(rhyme, 26);
    forn (i, 26) {
        if (rhyme[i] == 0) continue;
        // io::pr(rexp);
        ll sum = 0;
        int last_exp = i == 0 ? 1 : max(1, rhyme[i - 1]);
        // cout << last_exp << ", " << rhyme[i] << endl;
        forn (j, r.size()) {
            rexp[j] = (rexp[j] * mod_exp(r[j], rhyme[i] - last_exp) + MOD) % MOD;
            sum = (sum + rexp[j] + MOD) % MOD;
        }
        prod = (prod * sum + MOD) % MOD;
    }
    // io::pr(r);
    // cout << prod << endl;

    ofstream out("poetry.out");
    out << prod << endl;
    return 0;
}