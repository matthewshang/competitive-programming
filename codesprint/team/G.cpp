#include <bits/stdc++.h>
using namespace std;

pair<bool, bool> ask(int a, int b) {
    cout << "ASK " << a << ' ' << b << endl;
    cout.flush();
    string S, A;
    cin >> S >> A;
    return { S == "yes", A == "yes" };
}

void guess(int s, int a) {
    cout << "GUESS " << s << ' ' << a << endl;
    cout.flush();
    exit(0);
}

// S on the left: S started true, A started false
void go1(int l, int m, int r) {
    int low_s = l;
    int high_s = m;
    int low_a = m;
    int high_a = r;
    while (high_s - low_s > 1 || high_a - low_a > 1) {
        int mid_s = (low_s + high_s + 1) / 2;
        int mid_a = (low_a + high_a + 1) / 2;
        auto [Sn, An] = ask(mid_s, mid_a);
        if (Sn) {
            low_s = mid_s;
        } else {
            high_s = mid_s - 1;
        }
        if (An) {
            high_a = mid_a;
        } else {
            low_a = mid_a + 1;
        }
    }
    auto [Sn, An] = ask(high_s, low_a);
    if (Sn) {
        low_s = high_s;
    }
    if (!An) {
        low_a = high_a;
    }
    guess(low_s, low_a);
}

// S on the right: S started false, A started true
void go2(int l, int m, int r) {
    int low_s = m;
    int high_s = r;
    int low_a = l;
    int high_a = m;
    while (high_s - low_s > 1 || high_a - low_a > 1) {
        int mid_s = (low_s + high_s + 1) / 2;
        int mid_a = (low_a + high_a + 1) / 2;
        auto [Sn, An] = ask(mid_a, mid_s);
        if (Sn) {
            high_s = mid_s;
        } else {
            low_s = mid_s + 1;
        }
        if (An) {
            low_a = mid_a;
        } else {
            high_a = mid_a - 1;
        }
    }
    auto [Sn, An] = ask(high_a, low_s);
    if (!Sn) {
        low_s = high_s;
    }
    if (An) {
        low_a = high_a;
    }
    guess(low_s, low_a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int low = 1;
    int high = 500;
    while (low < high) {
        int mid = (low + high) / 2;
        auto [S, A] = ask(1, mid);
        if (S && A) {
            high = mid;
        } else if (!S && !A) {
            low = mid + 1;
        } else if (S && !A) {
            go1(low, mid, high);
        } else {
            go2(low, mid, high);
        }
    }
    guess(low, low);

    return 0;
}