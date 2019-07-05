#include "bits/stdc++.h"

using namespace std;

using ll = long long;

bool good(string& s, int a, int b) {
   int x = 0, y = 0;
   for (int i = a; i < b; i++) {
       if (s[i] == '0') x++;
       else y++;
   }
   return x != y;
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);
   
   int n; cin >> n;
   string s; cin >> s;

   if (good(s, 0, n)) {
       cout << "1\n" << s << endl;
   } else {
       for (int i = 1; i < n; i++) {
           if (good(s, 0, i) && good(s, i, n)) {
               cout << "2\n";
               cout << s.substr(0, i) << " " << s.substr(i, n - i) << endl;
               break;
           }
       }
   } 
   return 0;
}
