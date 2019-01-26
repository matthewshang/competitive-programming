#include "bits/stdc++.h"

using namespace std;

#define MOD 1000000007

#define MAXN 5000
int n, m, k;
map<int, vector<int>> words;
int rhyme[26];
map<int, int> c;
int* s;
int* len_count;

int main() {
    ifstream in("poetry.in");
    in >> n >> m >> k;
    s = new int[k + 1];
    len_count = new int[k + 1]; 
    for (int i = 0; i <= k; i++) {
        s[i] = 0;
        len_count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int syl, cla;
        in >> syl >> cla;
        auto it = words.find(cla);
        if (it != words.end()) {
            it->second.push_back(syl);
        } else {
            words.insert(make_pair(cla, vector<int>{syl}));
        }
        len_count[syl]++;
    }

    for (int i = 0; i < 26; i++) rhyme[i] = 0;
    for (int i = 0; i < m; i++) {
        char c;
        in >> c;
        rhyme[c - 'A']++;
    }
    // for (int i = 0; i < 26; i++) cout << rhyme[i] << ", ";
    // cout << endl;

    // for (int i = 0; i <= k; i++) {
    //     cout << len_count[i] << ", ";
    // }
    // cout << endl;

    s[0] = 1;
    s[1] = len_count[1];
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            s[i] += len_count[j] * s[i - j]; 
        }
    } 
    s[0] = 0;

    // cout << "s: ";
    // for (int i = 0; i <= k; i++) {
    //     cout << s[i] << ", ";
    // }
    // cout << endl;

    for (const auto& it : words) {
        int cla = it.first;
        auto it2 = c.find(cla);
        if (it2 == c.end()) {
            c.insert(make_pair(cla, 0));
        }
        int total = 0;
        for (int len : it.second) {
            total += s[k - len]; 
        }
        c[cla] += total;
    }

    // for (auto& it : c) {
    //     cout << it.first << ", " << it.second << endl;
    // }

    int result = 1;
    for (int i = 0; i < 26; i++) {
        int mul = 0;
        int p = rhyme[i];
        if (p == 0) continue;
        for (auto& it : c) {
            int q = 1;
            for (int j = 0; j < p; j++) {
                q = (q * it.second) % MOD;
            }
            mul = (mul + q) % MOD;
        }
        result = (result * mul) % MOD;
    }
    // cout << result << endl;
    ofstream out("poetry.out");
    out << result << endl;

    return 0;
}