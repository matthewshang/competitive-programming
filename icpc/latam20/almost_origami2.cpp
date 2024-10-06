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
    int n, m;
    cin >> n >> m;

    if (n != 1) {
        cout << "*" << "\n";
        return 0;
    }

    vector<int> s;
    const int MAX_DEPTH = 10;
    vector<int> best(m);
    auto explore = [&](int depth, auto& explore) -> bool {
        if (s.back() == m) {
            return true;
        }
        if (depth == MAX_DEPTH) {
            return s.back() == m;
        }

        for (int i = 0; i < int(s.size()); i++) {
            for (int j = i; j < int(s.size()); j++) {
                int sum = s[i] + s[j];
                if (sum > s.back()) {
                    s.push_back(sum);
                    if (explore(depth + 1, explore)) {
                        return true;
                    }
                    s.pop_back();
                }
            }
        }
        return false;
    };

    s.push_back(1);
    explore(0, explore);
    dbg(s);

    return 0;
}