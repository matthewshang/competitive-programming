#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 */

int main() {
    string s;
    getline(cin, s);
    char avg = accumulate(s.begin(), s.end(), int(0)) / s.size();
    cout << avg << "\n";
    return 0;
}