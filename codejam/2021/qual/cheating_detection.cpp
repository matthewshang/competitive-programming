#include "bits/stdc++.h"
using namespace std;

const int N = 100;
const int Q = 10000;

double f(double x) {
    return 1.0 / (1.0 + exp(-x));
}

int solve(vector<string>& c) {
    vector<int> diff(Q);
    vector<int> correct(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (c[i][j] == '1') {
                diff[j]++;
                correct[i]++;
            }
        }
    }

    auto inv = [](double p) -> double {
        double ex = exp(6.0 * p);
        return log(-(ex - 1.0) / (ex - exp(6.0))) + 3.0;
    };

    vector<double> s(N);
    for (int i = 0; i < N; i++) {
        double prop = correct[i] / double(Q);
        s[i] = clamp(inv(prop), -3.0, 3.0);
    }

    vector<double> q(Q);
    for (int i = 0; i < Q; i++) {
        double prop = diff[i] / double(N);
        q[i] = clamp(-inv(prop), -3.0, 3.0);
    }

    vector<int> hard_right(N);
    vector<double> hard_expect(N);
    const double HARD_THRESHOLD = 1.75;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (q[j] > HARD_THRESHOLD) {
                double p = f(s[i] - q[j]);
                hard_expect[i] += p;
                hard_right[i] += c[i][j] == '1';
            }
        }
    }

    vector<double> discrep(N);
    for (int i = 0; i < N; i++) {
        discrep[i] = abs(hard_right[i] - hard_expect[i]);
    }
    return max_element(discrep.begin(), discrep.end()) - discrep.begin() + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> choices(N);
    int T, P; cin >> T >> P;
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 0; i < N; i++) {
            cin >> choices[i];
        }
        cout << "Case #" << tc << ": " << solve(choices) << '\n';
    }
    
    return 0;
}