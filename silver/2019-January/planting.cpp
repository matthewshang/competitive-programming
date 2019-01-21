#include "bits/stdc++.h"

using namespace std;

struct Node {
    Node* parent;
    int id;
    vector<Node*> children;

    int color;
    set<int> neighbors;

    Node(int _id) : parent(nullptr), id(_id), color(-1) {};

    void print() {
        cout << "id: " << id << " parent: " << (parent ? parent->id : -1) << " color: " << color << endl;
        cout << "children: ";
        for (Node* c : children) {
            cout << c->id << ", ";
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
        nodes[a].children.push_back(&nodes[b]);
        nodes[b].parent = &nodes[a];
    }

}

void color_child(Node* node) {
    Node* paren = node->parent;
    set<int>& n = paren->neighbors;

    int color = 0;
    while(n.find(color) != n.end()) {
        color++;
    }
    if (color > max_color) {
        max_color = color;
    }

    node->color = color;
    n.insert(color);
    node->neighbors.insert(color);
    node->neighbors.insert(paren->color);

    for (Node* c : node->children) {
        color_child(c);
    }
}

int main() { 
    init(); 
    // for (int i = 0; i < n; i++) {
    //     nodes[i].print();
    //     cout << endl;
    // }

    nodes[0].color = 0;
    nodes[0].neighbors.insert(0);
    for (Node* c : nodes[0].children) {
        color_child(c);
    }
    
    // for (int i = 0; i < n; i++) {
    //     nodes[i].print();
    //     cout << endl;
    // }
    // cout << max_color + 1 << endl;
    ofstream out("planting.out");
    out << max_color + 1 << endl;
    return 0; 
}
