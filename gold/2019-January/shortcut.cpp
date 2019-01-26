#include "bits/stdc++.h"

using namespace std;

#define MAXN 10000
int N, M, T;
int* c;
int graph[MAXN][MAXN];

int main() {
    ifstream in("shortcut.in");
    in >> N >> M >> T;
    c = new int[N];
    for (int i = 0; i < N; i++) 
        in >> c[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, t;
        in >> a >> b >> t;
        graph[a][b] = t;
        graph[b][a] = t;
    }

    bool visited

    return 0;
}