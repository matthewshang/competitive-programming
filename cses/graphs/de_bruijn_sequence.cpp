#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-12-31
 * Source: CSES
 * Summary: Construct a directed graph with 2^(n-1) nodes with 2 outgoing edges
 * (0/1) per node. Each node corresponds to a string of length n-1, and an 
 * outgoing edge represents the nth character. Each edge points to the string
 * of length n-1 formed by deleting the first character and adding the edge's 
 * character. Then run Hierholzer's algorithm for Eulerian circuit in a directed 
 * graph. 
 */

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "01\n";
        return 0;
    }

    // Prepare graph
    int N = 1 << (n - 1);
    vector<vector<int>> adj(N);
    for (int v = 0; v < N; v++) {
        int next = (v << 1) & (N - 1);
        adj[v].push_back(next);
        adj[v].push_back(next | 1);
    }

    // Build circuit
    stack<int> tour;
    function<void(int)> find_tour = [&](int u) {
        while (!adj[u].empty()) {
            int to = adj[u].back();
            adj[u].pop_back();
            find_tour(to);
        }
        tour.push(u);
    };
    find_tour(0);

    // Build string using edges from the tour
    string res(n - 1, '0');
    tour.pop();
    while (!tour.empty()) {
        int next = tour.top();
        res += '0' + (next & 1);
        tour.pop();
    }
    cout << res << '\n';
    
    return 0;
}