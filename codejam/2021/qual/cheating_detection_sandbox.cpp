#include "bits/stdc++.h"
using namespace std;

string to_string(char c) { 
    return string(1, c); 
}
string to_string(const char* s) { 
    return (string)s; 
}
string to_string(string s) { 
    return s; 
}
string to_string(bool b) { 
    return b ? "true" : "false"; 
}
string to_string(vector<bool> v) { 
    string res = "{"; 
    for (int i = 0; i < int(v.size()); i++)
        res += char('0' + v[i]);
    res += "}"; return res; 
}
template <size_t SZ> string to_string(bitset<SZ> b) { 
    string res = "";
    for (int i = 0; i < int(SZ); i++)
        res += char('0' + b[i]);
    return res; 
}
template<class A, class B> string to_string(pair<A, B> p);
template<class T> string to_string(T& v) {
    bool fst = 1; string res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += to_string(x);
    }
    res += "}"; return res;
}
template<class A, class B> string to_string(pair<A, B> p) { 
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; 
}

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); 
    if (sizeof...(t)) cerr << ", ";
	DBG(t...); 
}
#ifdef LOCAL
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
	#define dbg(...) 0
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double f(double x) {
    return 1.0 / (1.0 + exp(-x));
}

const int N = 100;
// const int N = 10;
const int Q = 10000;
// const int Q = 10;

// ~40%
int solve1(vector<string>& c) {
    vector<int> D(Q);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (c[i][j] == '1') {
                D[j]++;
            }
        }
    }

    const int HARD = 10;
    vector<int> hard_count(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (c[i][j] == '1' && D[j] <= HARD) {
                hard_count[i]++;
            }
        }
    }
    return max_element(hard_count.begin(), hard_count.end()) - hard_count.begin();
}

// ~80%
int solve2(vector<string>& c) {
    vector<int> D(Q);
    vector<int> correct(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (c[i][j] == '1') {
                D[j]++;
                correct[i]++;
            }
        }
    }
    vector<double> score(Q);
    for (int i = 0; i < Q; i++) {
        score[i] = 1.0 - D[i] / double(N);
        // score[i] = score[i] * score[i] * score[i];
    }
    vector<double> skill(N);
    for (int i = 0; i < N; i++) {
        skill[i] = 1.0 - correct[i] / double(Q);
    }

    vector<double> player_score(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (c[i][j] == '1') {
                player_score[i] += skill[i] * score[j] * score[j] * score[j] * score[j];
            } else {
                player_score[i] -= 0.2 * skill[i] * score[j] * score[j];
            }
        }
    }
    return max_element(player_score.begin(), player_score.end()) - player_score.begin();
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
    return max_element(discrep.begin(), discrep.end()) - discrep.begin();
}

int gen(vector<string>& choices) {
    vector<double> S(N);
    auto gen33 = uniform_real_distribution<double>(-3, 3);
    for (int i = 0; i < N; i++) {
        S[i] = gen33(rng);
    }
    vector<double> D(Q);
    for (int i = 0; i < Q; i++) {
        D[i] = gen33(rng);
    }
    // dbg(S);
    // dbg(D);
    int cheater = uniform_int_distribution<int>(0, N - 1)(rng);
    // int cheater = 0;
    auto gen01 = uniform_real_distribution<double>(0, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            double p = f(S[i] - D[j]);
            if (i == cheater) {
                p = 0.5 + 0.5 * p;
            }
            choices[i][j] = (gen01(rng) < p) ? '1' : '0';
        }
    }
    // dbg(cheater);
    return cheater;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> choices(N, string(Q, '0'));
    int right = 0;
    // const int T = 1;
    const int T = 200;
    for (int i = 0; i < T; i++) {
        int who = gen(choices);
        int guess = solve(choices);
        if (who == guess) {
            right++;
        }
        // dbg(who, guess);
    }
    dbg(right);

    // int T, P; cin >> T >> P;
    // for (int tc = 1; tc <= T; tc++) {
    //     dbg(correct);
    // }
    
    return 0;
}
