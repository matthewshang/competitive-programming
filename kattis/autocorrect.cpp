#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-08-21
 * Source: NCPC 2016
 * Summary: Build a trie with extra edges for the backspaced and autocompleted
 * words. BFS to get shortest distances and then answer queries by moving down
 * the trie.
 */

constexpr int N = 1000001;

struct trie_node {
    array<int, 26> next; 
    int prev, jump, keystrokes;

    trie_node() : prev{-1}, jump{-1}, keystrokes{N} {
        fill(next.begin(), next.end(), -1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<trie_node> trie(1);
    int trie_size = 1;
    auto insert = [&](const string& s) {
        int cur = 0;
        for (int i = 0; i < int(s.size()); i++) {
            int c = s[i] - 'a';
            if (trie[cur].next[c] == -1) {
                trie.push_back(trie_node());
                trie[trie_size].prev = cur;
                trie[cur].next[c] = trie_size++;
            }
            cur = trie[cur].next[c];
        }

        int last = cur;
        while (cur != 0) {
            if (trie[cur].jump != -1) {
                break;
            }
            trie[cur].jump = last;
            cur = trie[cur].prev;
        }
    };

    int n, m;
    cin >> n >> m;
    for (int w = 0; w < n; w++) {
        string word;
        cin >> word;
        insert(word);
    }

    queue<int> q({0});
    trie[0].keystrokes = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int cur_keystrokes = trie[cur].keystrokes + 1;
        auto explore = [&](int node) {
            if (node != -1 && trie[node].keystrokes > cur_keystrokes) {
                trie[node].keystrokes = cur_keystrokes;
                q.push(node);
            }
        };

        for (int to : trie[cur].next) {
            explore(to);
        }
        explore(trie[cur].prev);
        explore(trie[cur].jump);
    }

    while (m--) {
        string word;
        cin >> word;

        int word_size = word.size();
        int min_keystrokes = word_size;
        int cur = 0;
        for (int i = 0; i < word_size; i++) {
            int j = word[i] - 'a';
            cur = trie[cur].next[j];
            if (cur == -1) {
                break;
            }
            min_keystrokes = min(min_keystrokes, trie[cur].keystrokes + word_size - i - 1);
        }
        cout << min_keystrokes << '\n';
    }

    return 0;
}