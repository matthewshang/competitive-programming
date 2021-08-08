#include <bits/stdc++.h>
using namespace std;

const array<string, 10> digits = {
    "xxxxx"
    "x...x"
    "x...x"
    "x...x"
    "x...x"
    "x...x"
    "xxxxx",
    "....x"
    "....x"
    "....x"
    "....x"
    "....x"
    "....x"
    "....x",
    "xxxxx"
    "....x"
    "....x"
    "xxxxx"
    "x...."
    "x...."
    "xxxxx",
    "xxxxx"
    "....x"
    "....x"
    "xxxxx"
    "....x"
    "....x"
    "xxxxx",
    "x...x"
    "x...x"
    "x...x"
    "xxxxx"
    "....x"
    "....x"
    "....x",
    "xxxxx"
    "x...."
    "x...."
    "xxxxx"
    "....x"
    "....x"
    "xxxxx",
    "xxxxx"
    "x...."
    "x...."
    "xxxxx"
    "x...x"
    "x...x"
    "xxxxx",
    "xxxxx"
    "....x"
    "....x"
    "....x"
    "....x"
    "....x"
    "....x",
    "xxxxx"
    "x...x"
    "x...x"
    "xxxxx"
    "x...x"
    "x...x"
    "xxxxx",
    "xxxxx"
    "x...x"
    "x...x"
    "xxxxx"
    "....x"
    "....x"
    "xxxxx",
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 7> exp;
    for (int i = 0; i < 7; i++) {
        cin >> exp[i];
    }

    auto get_digit = [&]() -> int {
        string s;
        if (exp[0].empty()) return -1;
        for (int i = 0; i < 7; i++) {
            s += exp[i].substr(0, 5);
            exp[i].erase(exp[i].begin(), exp[i].begin() + 5);
        }

        if (!exp[0].empty()) {
            for (int i = 0; i < 7; i++) {
                exp[i].erase(exp[i].begin());
            }
        }

        for (int d = 0; d < 10; d++) {
            if (digits[d] == s) return d;
        }
        return 10;
    };

    int64_t a = 0;
    while (true) {
        int d = get_digit();
        if (d == 10) break;
        a = a * 10 + d;
    }

    int64_t b = 0;
    while (true) {
        int d = get_digit();
        if (d == -1) break;
        b = b * 10 + d;
    }

    int64_t res = a + b;
    vector<int> ds;
    while (res) {
        ds.push_back(res % 10);
        res /= 10;
    }
    reverse(ds.begin(), ds.end());

    array<string, 7> out;
    for (int i = 0, n = ds.size(); i < n; i++) {
        const string& rep = digits[ds[i]];
        for (int j = 0; j < 7; j++) {
            out[j] += rep.substr(j * 5, 5);
            if (i != n - 1) {
                out[j] += '.';
            }
        }
    }

    for (const auto& line : out) {
        cout << line << '\n';
    }

    return 0;
}