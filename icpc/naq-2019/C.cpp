#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, D; cin >> P >> D;
    vector<array<int64_t, 2>> dist(D + 1);
    int64_t V = 0;
    for (int i = 0; i < P; i++) {
        int d, a, b; cin >> d >> a >> b;
        dist[d][0] += a;
        dist[d][1] += b;
        V += a + b;
    }

    int64_t A = 0, B = 0;
    for (int d = 1; d <= D; d++) {
        if (dist[d][0] > dist[d][1]) {
            cout << "A ";
            int64_t wa = dist[d][0] - ((dist[d][0] + dist[d][1]) / 2 + 1);
            cout << wa << ' ' << dist[d][1] << '\n';
            A += wa;
            B += dist[d][1];
        } else {
            cout << "B ";
            int64_t wb = dist[d][1] - ((dist[d][0] + dist[d][1]) / 2 + 1);
            cout << dist[d][0] << ' ' << wb << '\n';
            A += dist[d][0];
            B += wb;
        }
    }
    cout << fixed << setprecision(6) << (double(abs(A - B)) / V) << '\n';

    return 0;
}