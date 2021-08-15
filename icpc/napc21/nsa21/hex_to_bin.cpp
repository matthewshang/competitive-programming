#include <bits/stdc++.h>
using namespace std;

uint8_t base16_to_base10(char d) {
    if ('0' <= d && d <= '9') {
        return d - '0';
    } else {
        return 10 + (d - 'a');
    }
}

char base10_to_base16(uint8_t v) {
    if (0 <= v && v <= 9) {
        return '0' + v;
    } else {
        return 'a' + (v - 10);
    }
}

int main() {
    string data;
    vector<array<int, 2>> count(8 * 16);
    vector<bitset<8 * 16>> bits(20);
    for (int t = 0; t < 20; t++) {
        getline(cin, data);
        for (int i = 0; i < 16; i++) {
            char c = data[i];
            uint8_t v = base16_to_base10(c);
            bitset<8> b(v);
            for (int j = 0; j < 8; j++) {
                bits[t][i * 8 + j] = b[j];
                count[i * 8 + j][b[j]]++;
            }
            // cout << b;
        }
        // cout << endl;
    }

    set<int> out;
    for (int i = 0; i < 8 * 16; i++) {
        if (count[i][0] != 20 && count[i][0] != 0) {
            out.insert(i);
        }
    }
    cout << out.size() << endl;

    vector<bitset<48>> cool(20);
    for (int t = 0; t < 20; t++) {
        int k = 0;
        for (int i = 0; i < 8 * 16; i++) {
            if (out.find(i) != out.end()) {
                // cout << bits[t][i];
                cool[t][k] = bits[t][i];
                k++;
            } else {
                // cout << i << " ";
                cout << bits[t][i];
            }
        }
    cout << endl;
        // cout << endl;
    }

    map<pair<int, int>, set<int>> mp;
    for (int t = 0; t < 20; t++) {
        vector<int> x(12);
        for (int i = 0; i < 12; i++) {
            cout << cool[t][i] << cool[t][12 + i] << cool[t][24 + i] << cool[t][36 + i] << " ";
            x[i] = (cool[t][i] << 3) | (cool[t][12 + i] << 2) | (cool[t][24 + i] << 1) | cool[t][36 + i];
        }
        for (int i = 0; i < 11; i++) {
            mp[{x[i], i}].insert(x[i + 1]);
        }
        cout << endl;
    }

    cout << mp.size() << endl;
    for (const auto& it : mp) {
        cout << it.first.first << " " << it.first.second << " ";
        cout << it.second.size() << " ";
        for (int x : it.second) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}