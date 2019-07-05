#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
   ios::sync_with_stdio(0); cin.tie(0);
   
   int n; cin >> n;
   vector<int> deg(n, 0);
   for (int i = 0; i < n - 1; i++) {
       int u, v; cin >> u >> v;
       deg[u - 1]++; deg[v - 1]++;
   }

   for (int d : deg) {
       if (d == 2) {
           cout << "NO\n";
           return 0;
       }
   }
   cout << "YES\n";
   return 0;
}
