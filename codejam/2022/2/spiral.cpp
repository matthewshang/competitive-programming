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

void solve(int tc) {
    int n, k;
    cin >> n >> k;
    if (k % 2 == 1 || k < n - 1) {
        cout << "Case #" << tc << ": IMPOSSIBLE\n";
        return;
    }
    
    auto cell = [&](int x, int y) -> int {
        int m = max(abs(x), abs(y));
        int l = (n / 2 - m);
        int start = n * n - (n - 2 * l) * (n - 2 * l);
        if (y == m) {
            return start + x + m + 1;
        } else if (x == m) {
            return start - y + m + 1 + 2 * m;
        } else if (y == -m) {
            return start - x + m + 1 + 4 * m;
        } else {
            return start + y + m + 1 + 6 * m;
        }
    };

    vector<pair<int, int>> shortcut;
    auto edge = [&](int xf, int yf, int xt, int yt) {
        assert(xf == xt || yf == yt);
        int cf = cell(xf, yf);
        int ct = cell(xt, yt);
        assert(cf < ct);
        if (cf + 1 != ct) {
            shortcut.push_back({cf, ct});
        }
    };

    int left = k + 1;
    bool done = false;
    for (int l = n / 2; l > 0; l--) {
        if (!done) {
            for (int x = 0; x < l && !done; x++) {
                if ((x + l + 1) + (l) + (x) == left) {
                    for (int y = l; y >= 1; y--) {
                        edge(x, y, x, y - 1);
                    }
                    for (int xx = x; xx >= 1; xx--) {
                        edge(xx, 0, xx - 1, 0);
                    }
                    done = true;
                } 
            }
        }

        if (!done) {
            left -= 2 * l;
            for (int y = 0; y > -l && !done; y--) {
                if ((-y + l + 1) + (l) + (-y) == left) {
                    for (int x = l; x >= 1; x--) {
                        edge(x, y, x - 1, y);
                    }
                    for (int yy = y; yy <= -1; yy++) {
                        edge(0, yy, 0, yy + 1);
                    }
                    done = true;
                }
            }
        }

        if (!done) {
            left -= 2 * l;
            for (int x = 0; x > -l && !done; x--) {
                if ((-x + l + 1) + (l) + (-x) == left) {
                    for (int y = -l; y <= -1; y++) {
                        edge(x, y, x, y + 1);
                    }
                    for (int xx = x; xx <= -1; xx++) {
                        edge(xx, 0, xx + 1, 0);
                    }
                    done = true;
                }
            }
        }

        if (!done) {
            left -= 2 * l;
            for (int y = 0; y < l && !done; y++) {
                if ((y + l + 1) + (l) + (y) == left) {
                    for (int x = -l; x <= -1; x++) {
                        edge(x, y, x + 1, y);
                    }
                    for (int yy = y; yy >= 1; yy--) {
                        edge(0, yy, 0, yy - 1);
                    }
                    done = true;
                }
            }
        }
        
        if (!done) {
            left -= 2 * l;
        }
    }

    cout << "Case #" << tc << ": " << shortcut.size() << "\n";
    for (auto [a, b] : shortcut) {
        cout << a << " " << b << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc++) {
        solve(tc);
    }

    return 0;
}