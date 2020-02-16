#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(bool x) { cout << (x ? "true" : "false"); }

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

    auto query = [](vector<int>& x) -> pair<int, int> {
        cout << "?";
        for (int val : x) cout << " " << val;
        cout << endl;
        pair<int, int> ans;
        cin >> ans.first;
        if (ans.first == -1) exit(0);
        cin >> ans.second;
        return ans;
    };

    int n, k; cin >> n >> k;
    // Ask n - k + 1 times: [1, k], [2, k + 1], ... ,[n - k + 1, n]
    // If we know k, great. Ask for the k we know, and we're done
    // Otherwise we know at least one
    // Still have k - 1 queries
    //
    //
    // 2 ? ? 9
    // Q(1, 2, 3) -> 1 2
    // Q(2, 3, 4) -> 4 9
    //
    // 1 2 3 1; m = 3, k = 3
    // ? ? 3 ?
    // 
    // Ask k times: the next set of k that are unknown
    // After this, we know l. If l == k, ask one more time and we're done
    // We still have more than n - k + 1
    // We stopped because there were k - 1 unknown => n = k - 1 + l
    // Pick k - 2 of the unknown, fix one of the known, ask for every pair
    // example:
    // Q(1, 2, 4) -> 4 9
    // - If we know a new one, epic
    // - 


    return 0;
}
