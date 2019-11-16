#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    int depth = (int)ceil(log2(n));
    int sz = 1 << depth;
    vector<int> tree(sz + 1, 0); 
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        tree[a]++;
    }

    auto calc = [&]() -> int {
        int ans = 0;
        for (int layer = depth; layer >= 1; layer--) {
            for (int i = 1 << (layer - 1); i < 1 << layer; i++) {
                if (tree[i] >= k) {
                    return ans;
                }

                if (layer != depth) {
                    if (tree[i] + tree[i * 2] >= k)
                        return ans + k - tree[i];
                    tree[i] += tree[i * 2];
                    if (tree[i] + tree[i * 2 + 1] >= k)
                        return ans + k - tree[i];
                    tree[i] += tree[i * 2 + 1];
                }
            }
        }
    }

    cout << calc() << endl;
    return 0;
}
