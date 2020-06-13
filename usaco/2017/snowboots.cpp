#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define ford(i, n, e) for (int i = (n); i > (e); i--)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int n, b;
int f[250];
int s[250];
int d[250];

int find_jump(int pos, int boot) {
    ford(i, min(pos + d[boot], n), pos) {
        if (s[boot] >= f[i]) {
            return i;
        }
    }
    return -1;
}
int find_jump_min(int pos, int boot) {
    pii min_discard = mp(INT_MAX, -1);
    ford(i, min(pos + d[boot], n), pos) {
        if (s[boot] >= f[i]) {
            int disc = 0;
            while (find_jump(i, boot + disc) == -1 && boot + disc < b) {
                disc++;
            }
            cout << boot + disc << endl;
            if (boot + disc == b) continue;
            if (min_discard.F > disc) {
                min_discard.F = disc;
                min_discard.S = i;
            } 
        }
    }
    return min_discard.S;
}

int main() {
    // ifstream in("boots/2.in");
    ifstream in("snowboots.in");
    in >> n >> b;
    forn(i, n) in >> f[i];
    forn(i, b) in >> s[i] >> d[i];

    int pos = 0;
    int boot = 0;
    while (pos < n) {
        int jmp = -1;
        while (boot < b) {
            jmp = find_jump_min(pos, boot);
            if (jmp != -1 && s[boot + 1] >= f[pos]) 
                break;
            boot++;
        }
        assert(jmp != -1);
        pos = jmp;
    }

    cout << boot << endl;
    ofstream out("snowboots.out");
    out << boot << endl;
    return 0;
}