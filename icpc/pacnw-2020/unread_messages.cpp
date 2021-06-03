#include <bits/stdc++.h>
using namespace std;

// Every time a new message is sent, we add n unread messages (1 for each
// person) and subtract the number of messages the latest sender read.
// This is just the number of messages between now and the last time
// the latest sender sent something.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<int, int> last_read;
    int64_t total_unread = 0;
    for (int i = 1; i <= m; i++) {
        int s;
        cin >> s;
        total_unread += n;
        total_unread -= i - last_read[s];
        last_read[s] = i;
        cout << total_unread << '\n';
    }

    return 0;
}