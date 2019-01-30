#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

inline int hash_ftwo(string s) {
    return (s[0] - 'A') * 26 + s[1] - 'A';
}

inline int hash_cs(string c, string s) {
    return hash_ftwo(c) * hash_ftwo(s);
}

int main() {
    int n;
    map<int, vector<pair<int, int>>> count;

    ifstream in("citystate.in");
    in >> n;
    forn(i, n) {
        string c, s;
        in >> c >> s;
        int h = hash_cs(c, s);
        count[h].emplace_back(hash_ftwo(c), hash_ftwo(s));
    }

    int total = 0;
    for (const auto& p : count) {
        const auto& v = p.second;
        forn(i, v.size()) {
            fora(j, i + 1, v.size()) {
                if (v[i].first == v[j].second && 
                    v[i].second == v[j].first &&
                    v[i].second != v[j].second) {
                    total++;
                }
            }
        }
    }

    ofstream out("citystate.out");
    out << total << endl;
    return 0;
}