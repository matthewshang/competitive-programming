#include "bits/stdc++.h"

using namespace std;

int n;
bool *marked;
bool *board;

#define CONV(row, col) ((row)*n + (col))

void read() {
    ifstream in("perimeter.in");
    in >> n;
    marked = new bool[n * n];
    board = new bool[n * n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            marked[i * n + j] = false;
            char c;
            in >> c;
            board[i * n + j] = c == '#' ? true : false;
        }
    }
}

int flood(int row, int col) {
    if (row < 0 || row >= n || col < 0 || col >= n || marked[CONV(row, col)]) {
        return 0;
    }
    if (!board[CONV(row, col)]) {
        return 0;
    }

    marked[CONV(row, col)] = true;
    return 1 + flood(row - 1, col) + flood(row + 1, col) + flood(row, col - 1) +
           flood(row, col + 1);
}

int flood2(int row, int col) {
    if (marked[CONV(row, col)]) {
        return 0;
    }

    marked[CONV(row, col)] = true;
    int exposed = 0;

    if (row - 1 < 0 || !board[CONV(row - 1, col)]) {
        exposed++;
    } else {
        exposed += flood2(row - 1, col);
    }
    if (row + 1 >= n || !board[CONV(row + 1, col)]) {
        exposed++;
    } else {
        exposed += flood2(row + 1, col);
    } 

    if (col - 1 < 0 || !board[CONV(row, col - 1)]) {
        exposed++;
    } else {
        exposed += flood2(row, col - 1);
    }
    if (col + 1 >= n || !board[CONV(row, col + 1)]) {
        exposed++;
    } else {
        exposed += flood2(row, col + 1);
    }

    return exposed;
}

int main() {
    read();
    int max_area = 0;
    vector<pair<int, pair<int, int>>> locs;
    pair<int, int> max_coord = make_pair(-1, -1);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (!marked[CONV(row, col)]) {
                int area = flood(row, col);
                // if (area > 0)
                //     cout << "area: " << area << endl;
                locs.push_back(make_pair(area, make_pair(row, col)));
                if (area > max_area) {
                    max_area = area;
                    // cout << max_coord.first << ", " << max_coord.second << endl;
                }
            }
        }
    }

    for (int i = 0; i < n * n; i++) {
        marked[i] = false;
    }
    int min_peri = 1e9;
    for (auto& p : locs) {
        if (p.first != max_area) {
            continue;
        }

        int peri = flood2(p.second.first, p.second.second);
        if (peri < min_peri) {
            min_peri = peri;
        }
    }

    // cout << max_area << " " << max_peri << endl;
    ofstream out("perimeter.out");
    out << max_area << " " << min_peri << endl;
    return 0;
}