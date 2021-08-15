#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ev;
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        ev.push_back({a, 1});
        ev.push_back({a + s, -1});
    }
    sort(ev.begin(), ev.end());

    int unlocks = 0;
    priority_queue<int, vector<int>, greater<int>> ws;
    for (auto [time, type] : ev) {
        if (type == 1) {
            while (!ws.empty() && ws.top() + m < time) {
                ws.pop();
            }
            if (ws.empty()) {
                unlocks++;
            } else {
                ws.pop();
            }
        } else {
            ws.push(time);
        }
    }

    cout << (n - unlocks) << '\n';

    return 0;
}