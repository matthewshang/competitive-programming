#pragma GCC optimize ("O2")

#include "bits/stdc++.h"

using namespace std;



int main() {
    ifstream input("7.in");
    ofstream output("shuffle.out");
    int n;
    input >> n;
    int graph[n];
    for (int i = 0; i < n; i++) {
        input >> graph[i];
        graph[i]--;
    }

    bool cycle[n];
    for (int j = 0; j < n; j++) cycle[j] = false;

    bool visited[n];

    for (int i = 0; i < n; i++) {
        if (cycle[i]) continue;

        for (int j = 0; j < n; j++) visited[j] = false;


        visited[i] = true;
        int current = graph[i];
        while (true) {
            if (visited[current]) {
                cycle[current] = true;
                break;
            }
            visited[current] = true;
            current = graph[current];
        }
    }

    int cycle_count = 0;
    for (int i = 0; i < n; i++) {
        if (cycle[i]) cycle_count++;
        // cout << cycle[i];
    }
    output << cycle_count << endl;
    // cout << endl;
    
    return 0;
}