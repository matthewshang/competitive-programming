#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }

template <typename T1, typename T2>
void pr(const pair<T1, T2>& p) {
    pr("{ "); pr(p.first); pr(", "); pr(p.second); pr(" }");
}

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (const auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int m; cin >> m;
    while (m--) {
        int n, T, a, b; cin >> n >> T >> a >> b;
        vector<pair<ll, int>> p(n);
        for (auto& x : p) {
            bool hard; cin >> hard;
            x.second = hard ? b : a;
        }
        for (auto& x : p) cin >> x.first;
        sort(p.begin(), p.end());
        p.emplace_back(T + 1, 0);
        // dbg(p);
        
        vector<int> easy(n);
        easy[0] = p[0].second == a;
        for (int i = 1; i < n; i++)
            easy[i] = easy[i - 1] + (p[i].second == a);
        int totale = easy[n - 1];

        int ans = 0;
        ll sum = 0;

        {
            ll e = min((ll)totale, (p[0].first - 1) / a);
            // dbg(totale, (p[0].first - 1) / a);
            if (e > 0) ans += e;
            ll h = min((ll)(n - totale), (p[0].first - 1 - a * e) / b);
            if (h > 0) ans += h;
        }

        for (int i = 0; i < n; i++) {
            sum += p[i].second;
            int tmp = 0;
            // dbg(i, sum);
            if (sum <= (p[i + 1].first - 1)) {
                tmp += i + 1;
                ll e = min((ll)totale - easy[i], (p[i + 1].first - 1 - sum) / a);
                if (e > 0) tmp += e;
                ll h = min((ll)(n - totale) - (i + 1 - easy[i]), (p[i + 1].first - 1 - sum - a * e) / b);
                if (h > 0) tmp += h;
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;

    }

    return 0;
}
