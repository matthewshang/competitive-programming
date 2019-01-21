#include "bits/stdc++.h"

using namespace std;

struct Node {
    int parent;
    int id;
    vector<int> children;

    int color;
    set<int> neighbors;

    Node(int _id) : parent(-1), id(_id), color(-1) {};

    void print() {
        cout << "id: " << id << " parent: " << parent << " color: " << color << endl;
        cout << "children: ";
        for (int c : children) {
            cout << c << ", ";
        }
        cout << endl;
    }
};

int n;
vector<Node> nodes;
int max_color = 0;

void init() {
    ifstream in("planting.in");
    in >> n;
    for (int i = 0; i < n; i++) {
        nodes.emplace_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        in >> a >> b;
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        a--;
        b--;
        nodes[a].children.push_back(b);
        nodes[b].parent = a;
    }

    for (int i = 0; i < n; i++) {
        nodes[i].print();
        cout << endl;
    }
}

void color_child(int idx) {
    int p = nodes[idx].parent;
    set<int>& n = nodes[p].neighbors;
    int color = 0;
    while(n.find(color) != n.end()) {
        color++;
    }
    if (color > max_color) {
        max_color = color;
    }
    nodes[idx].color = color;
    n.insert(color);
    nodes[idx].neighbors.insert(color);
    nodes[idx].neighbors.insert(nodes[p].color);
    for (int i : nodes[idx].children) {
        color_child(i);
    }
}

int main() { 
    init(); 
    nodes[0].color = 0;
    nodes[0].neighbors.insert(0);
    for (int i : nodes[0].children) {
        color_child(i);
    }
    
    for (int i = 0; i < n; i++) {
        nodes[i].print();
        cout << endl;
    }
    cout << max_color + 1 << endl;
    ofstream out("planting.out");
    out << max_color + 1 << endl;
    return 0; 
}
