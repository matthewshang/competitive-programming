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
    void pr(const vi& v) {
        forn (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T>
    void pr(T* arr, int n) {
        forn (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    ifstream in("starter.in");
    ofstream out("starter.out");
    return 0;
}