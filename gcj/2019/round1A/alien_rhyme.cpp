#include "bits/stdc++.h"

using namespace std;

template<int SIZE>
struct node {
    array<int, SIZE> next;
    int count;
};

constexpr int SIGMA = 26;
node<SIGMA> d[2000000];
int nxt = 0;

int make_node() {
    fill(d[nxt].next.begin(), d[nxt].next.end(), -1);
    d[nxt].count = 0;
    return nxt++;
}

void init_trie() {
    nxt = 0;
    make_node();
    make_node();
}

int dfs(int v, int p) {
    int ans = 0;
    for (int to = 0; to < SIGMA; to++) {
        if (d[v].next[to] != -1) {
            ans += dfs(d[v].next[to], v);
        }
    }
    if (d[v].count >= 2 && v != 1) {
        ans += 2;
        d[v].count -= 2;
    }
    d[p].count += d[v].count;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init_trie();

        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            string W; cin >> W;
            reverse(W.begin(), W.end());
            int cur = 1;
            for (char c : W) {
                if (d[cur].next[c - 'A'] == -1) {
                    d[cur].next[c - 'A'] = make_node();
                }
                cur = d[cur].next[c - 'A'];
            }
            d[cur].count++;
        }

        cout << "Case #" << tc << ": " << dfs(1, 0) << '\n';
    }

    return 0;
}