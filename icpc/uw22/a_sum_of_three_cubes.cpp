#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-01-31
 * Source: UW 2022
 * Summary: Precompute z's and enumerate all x,y.
 */

int64_t cube(int n) {
    return int64_t(n) * n * n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> residue_to_z(N);
    for (int z = 0; z < N; z++) {
        int residue = (N - (cube(z) % N)) % N;
        residue_to_z[residue].push_back(z);
    }

    vector<array<int, 3>> triples;
    for (int x = 0; x < N; x++) {
        for (int y = x + 1; y < N; y++) {
            int residue = (cube(x) + cube(y)) % N;
            for (int z : residue_to_z[residue]) {
                if (z > y) {
                    triples.push_back({x, y, z});
                }
            }
        }
    }

    cout << triples.size() << '\n';
    for (auto [x, y, z] : triples) {
        cout << x << " " << y << " " << z << '\n';
    }

    return 0;
}