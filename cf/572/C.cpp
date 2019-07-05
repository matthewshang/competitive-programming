#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> lay;
    vector<vector<int>> sum;
    lay.push_back(s);
    sum.push_back(vector<int>(n, 0));
 
    int gap = 1;
    while (n + 1 - gap * 2 > 0) {
        int sz = n + 1 - gap * 2;
        vector<int> l(sz), c(sz);
        for (int i = 0; i < sz; i++) {
            int add = lay.back()[i] % 10 + lay.back()[i + gap] % 10;
            l[i] = add;
        }
        for (int i = 0; i < sz; i++) {
            c[i] = l[i] >= 10 ? 1 : 0;
            c[i] += sum.back()[i] + sum.back()[i + gap];
        }
 
        lay.push_back(l);
        sum.push_back(c);
        gap *= 2;
    }
 
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        int level = (int)log2(r - l + 1);
        cout << sum[level][l - 1] << endl;
    }
    
    return 0;
}
