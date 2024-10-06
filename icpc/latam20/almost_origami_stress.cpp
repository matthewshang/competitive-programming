#include <bits/stdc++.h>
using namespace std;

string to_string(char c) { 
    return string(1, c); 
}
string to_string(const char* s) { 
    return (string)s; 
}
string to_string(string s) { 
    return s; 
}
string to_string(bool b) { 
    return b ? "true" : "false"; 
}
string to_string(vector<bool> v) { 
    string res = "{"; 
    for (int i = 0; i < int(v.size()); i++)
        res += char('0' + v[i]);
    res += "}"; return res; 
}
template <size_t SZ> string to_string(bitset<SZ> b) { 
    string res = "";
    for (int i = 0; i < int(SZ); i++)
        res += char('0' + b[i]);
    return res; 
}
template<class A, class B> string to_string(pair<A, B> p);
template<class T> string to_string(T& v) {
    bool fst = 1; string res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += to_string(x);
    }
    res += "}"; return res;
}
template<class A, class B> string to_string(pair<A, B> p) { 
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; 
}

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); 
    if (sizeof...(t)) cerr << ", ";
	DBG(t...); 
}
#ifdef LOCAL
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
	#define dbg(...) 0
#endif

int solve(int n) {
    vector<int> dp(n + 1, 1e9);
    vector<int> choice(n + 1);

    auto go_back = [&](int cur, set<int>& u, auto& go_back) -> void {
        if (cur == 1) {
            return;
        }
        u.insert(cur);

        if (!u.contains(choice[cur])) {
            go_back(choice[cur], u, go_back);
        }
        if (!u.contains(cur - choice[cur])) {
            go_back(cur - choice[cur], u, go_back);
        }
    };

    dp[1] = 0;
    choice[1] = 0;
    for (int d = 2; d <= n; d++) {
        for (int i = 1; i < d; i++) {
            set<int> used;
            go_back(i, used, go_back);
            go_back(d - i, used, go_back);
            int cost = used.size();
            if (cost < dp[d]) {
                dp[d] = cost;
                choice[d] = i;
            }
        }
    }
    // dbg(dp, choice);
    assert(dp[n] != 1e9);

    set<int> used;
    go_back(n, used, go_back);

    return used.size();
}

vector<set<bitset<101>>> bruted(100);

int brute(int n) {
    vector<int> best_masks;
    int best_size = n;
    auto contains = [&](int x, int p) -> bool {
        return x & (1 << p);
    };

    for (int mask = 0; mask < 1 << (n - 2); mask++) {
        int real = (1 << n) | (mask << 2) | 2;
        bool ok = true;
        for (int pos = 2; pos <= n; pos++) {
            if (contains(real, pos)) {
                bool ok2 = false;
                for (int i = 1; i < pos; i++) {
                    if (contains(real, i) && contains(real, pos - i)) {
                        ok2 = true;
                        break;
                    }
                }
                if (!ok2) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            if (__popcount(real) < best_size) {
                best_masks.clear();
                best_size = __popcount(real);
            }

            if (__popcount(real) == best_size) {
                best_masks.push_back(real);
            }
        }
    }
    // dbg(n, best_size - 1);
    // for (int x : best_masks) {
    //     dbg(bitset<25>(x));
    // }
    for (int x : best_masks) {
        bruted[n].insert(bitset<101>(x));
    }
    return best_size - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    const int CUT = 20;
    for (int i = 1; i <= CUT; i++) {
        brute(i);
    }
    // auto bake = [&](auto& bake, int m) -> set<bitset<101>> {
    //     if (m < CUT) {
    //         return bruted[m];
    //     }

    //     set<bitset<101>> res;
    //     int rn = m;
    //     for (int i = 1; i < m; i++) {
    //         auto a = bake(bake, i);
    //         auto b = bake(bake, m - i);
    //         for (const auto& x : a) {
    //             for (const auto& y : b) {
    //                 auto comb = x | y;
    //                 comb[m] = 1;
    //                 if (comb.count() < rn) {
    //                     rn = comb.count();
    //                     res.clear();
    //                 }
    //                 if (comb.count() == rn) {
    //                     res.insert(comb);
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // };
    // auto as = bake(bake, n);
    // dbg(as);
    // bitset<101> a;
    // bitset<101> bruh;
    // a[1] = 1;
    // step(0, n, a, bruh);

    // // for (int i = 1; i <= 100; i++) {
    // for (int i = 15; i <= 15; i++) {
    //     vector<int> seq;
    //     int cur = last[i];
    //     while (cur) {
    //         seq.push_back(cur);
    //         cur = last[cur];
    //     }
    //     reverse(seq.begin(), seq.end());

    //     dbg(seq);
    // }

    // for (int n = 2; n < 20; n++) {
    //     dbg(n, solve(n), brute(n));
    // }

    return 0;
}