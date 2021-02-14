#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int BS = 300;

    int L, C, N; cin >> L >> C >> N;
    const int BN = (L + 1) / BS + 1;
    const int END = L / BS;
    vector<int> tape(L + 1, 1);
    vector<int> lazy(BN, 0);
    vector<map<int, int>> cnt(BN);
    for (int i = 0; i < BN; i++) {
        cnt[i][1] = BS;
    }

    auto push = [&](int b) {
        if (lazy[b] != 0) {
            cnt[b].clear();
            cnt[b][lazy[b]] = BS;
            for (int i = b * BS; i < min((b + 1) * BS, L + 1); i++) {
                tape[i] = lazy[b];
            }
            lazy[b] = 0;
        }
    };

    auto get_times = [&](int c) -> int {
        int S = 0;
        for (int j = 0; j < END; j++) {
            if (lazy[j] == 0) {
                S += cnt[j][c];
            } else if (lazy[j] == c) {
                S += BS;
            }
        }
        push(END);
        for (int j = END * BS; j < L; j++) {
            if (tape[j] == c) {
                S++;
            }
        }
        return S;
    };

    for (int i = 0; i < N; i++) {
        int P, X, A, B; cin >> P >> X >> A >> B;
        int S = get_times(P);

        int M1 = ((long long)S * S + A) % L;
        int M2 = ((long long)(S + B) * (S + B) + A) % L;
        int l = min(M1, M2);
        int r = max(M1, M2);
        int bl = l / BS;
        int br = r / BS;
        if (bl == br) {
            push(bl);
            for (int j = l; j <= r; j++) {
                cnt[bl][tape[j]]--;
                tape[j] = X;
                cnt[bl][X]++;
            }
        } else {
            push(bl);
            for (int j = l; j <= (bl + 1) * BS - 1; j++) {
                cnt[bl][tape[j]]--;
                tape[j] = X;
                cnt[bl][X]++;
            }
            push(br);
            for (int j = br * BS; j <= r; j++) {
                cnt[br][tape[j]]--;
                tape[j] = X;
                cnt[br][X]++;
            }

            for (int j = bl + 1; j <= br - 1; j++) {
                lazy[j] = X;
            }
        }
    }

    int max_times = 0;
    for (int color = 1; color <= C; color++) {
        max_times = max(max_times, get_times(color));
    }
    cout << max_times << '\n';

    return 0;
}