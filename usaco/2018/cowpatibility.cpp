#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    #ifndef TESTING
    freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }

template <typename T1, typename T2>
void pr(pair<T1, T2>& p) {
    pr("{ "); pr(p.first); pr(", "); pr(p.second); pr(" }");
}

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
    cout << "}";
}

void pd() { cout << "]" << endl; }

template <typename T, typename... U>
void pd(T first, U... rest) {
    pr(first); if (sizeof...(rest)) cout << ", "; pd(rest...);
}

#ifdef TESTING
#define dbg(x...) cout << "[" << #x << "] = [", pd(x)
#else
#define dbg(...)
#endif

// size_t hsh()
//
// hash: ll has 64 bits. log2(1e6) < 20, so we can definitely fit 3 flavors in an ll

const vector<vector<vector<int>>> indices = {
    {{0}, {1}, {2}, {3}, {4}},
    {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}},
    {{0, 1, 2}, {0, 1, 3}, {0, 1, 4}, {0, 2, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 3}, 
     {1, 2, 4}, {1, 3, 4}, {2, 3, 4}},
    {{0, 1, 2, 3}, {0, 1, 2, 4}, {0, 1, 3, 4}, {0, 2, 3, 4}, {1, 2, 3, 4}},
    {{0, 1, 2, 3, 4}}
};

pair<ll, ll> hash_flavors(vector<ll>& f) {
    ll ans = 0;
    for (int i = 0; i < min((int)f.size(), 3); i++)
        ans = (ans << 20) | (f[i] & ((1 << 21) - 1));
    if (f.size() > 3) {
        ll hsh = 0;
        for (int i = 3; i < f.size(); i++)
            hsh = (hsh << 20) | (f[i] & ((1 << 21) - 1));

        return {ans, hsh};
    } 
    else {
        return {ans, 0};
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("cowpatibility");

    ll n; cin >> n;
    vector<array<ll, 5>> c(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++)
            cin >> c[i][j];
        sort(c[i].begin(), c[i].end());
    }

    ll ans = n * (n - 1) / 2;
    map<pair<ll, ll>, ll> count;
    for (int sz = 0; sz <= 4; sz++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < indices[sz].size(); j++) {
                vector<ll> f;
                for (int l : indices[sz][j])
                    f.push_back(c[i][l]);
                pair<ll, ll> hsh = hash_flavors(f);
                count[hsh]++;
            }
        }
        ll add = 0;
        for (auto& p : count)
            add += p.second * (p.second - 1) / 2;
        ans += (sz % 2 ? 1 : -1) * add;
        dbg(ans, add);
        count.clear();
    }

    cout << ans << endl;

    return 0;
}
