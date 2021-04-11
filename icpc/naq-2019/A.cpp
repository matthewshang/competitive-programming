#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<bool> val(n);
    for (int i = 0; i < n; i++) {
        char v; cin >> v;
        val[i] = (v == 'T');
    }

    string line;
    // Skip newline
    getline(cin, line);
    getline(cin, line);

    char tok;
    stringstream ss(line);
    stack<bool> eval;
    while (ss >> tok) {
        bool a, b;
        switch (tok) {
            case '*':
                a = eval.top(); eval.pop();
                b = eval.top(); eval.pop();
                eval.push(a & b);
                break;
            case '+':
                a = eval.top(); eval.pop();
                b = eval.top(); eval.pop();
                eval.push(a | b);
                break;
            case '-':
                a = eval.top(); eval.pop();
                eval.push(!a);
                break;
            default:
                eval.push(val[tok - 'A']);
        }
    }
    cout << (eval.top() ? 'T' : 'F') << endl;

    return 0;
}