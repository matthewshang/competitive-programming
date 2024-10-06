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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    if (m != 1) {
        cout << "*" << "\n";
        return 0;
    }

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
    dbg(dp, choice);
    assert(dp[n] != 1e9);

    set<int> used;
    go_back(n, used, go_back);

    for (int x : used) {
        cout << 1 << " " << choice[x] << "\n";
        cout << 1 << " " << (x - choice[x]) << "\n";
    }

    // set<int> reach;
    // reach.insert(1);
    // vector<int> last(n + 1);
    // for (int t = 0; t < 7; t++) {
    //     vector<int> found;
    //     for (int x : reach) {
    //         for (int y : reach) {
    //             found.push_back(x + y);
    //         }
    //     }
    //     for (auto f : found) {
    //         reach.insert(f);
    //     }
    // }

    // for (int i = 1; i <= 100; i++) {
    //     if (!reach.contains({1, i})) {
    //         dbg(i);
    //     }
    // }

    return 0;
}