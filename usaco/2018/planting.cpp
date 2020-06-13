#include "bits/stdc++.h"

using namespace std;

struct Node {
    Node *parent;
    int id;
    vector<Node *> children;

    int color;
    set<int> neighbors;

    Node(int _id) : parent(nullptr), id(_id), color(-1){};

    void print() {
        cout << "id: " << id << " parent: " << (parent ? parent->id : -1)
             << " color: " << color << endl;
        cout << "children: ";
        for (Node *c : children) {
            cout << c->id << ", ";
        }
        cout << endl;
    }
};

int n;
vector<Node> nodes;
int max_color = 1;

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

int main() {
    init();
    // for (int i = 0; i < n; i++) {
    //     nodes[i].print();
    //     cout << endl;
    // }

    stack<Node *> visit;
    nodes[0].color = 1;
    nodes[0].neighbors.insert(1);
    for (Node *c : nodes[0].children) {
        visit.push(c);
    }
    while (!visit.empty()) {
        Node *n = visit.top();
        visit.pop();
        Node *p = n->parent;
        set<int> &s = p->neighbors;

        int color = 1;
        if (s.size() == max_color) {
            color = max_color + 1;
        } else {
            while (s.find(color) != s.end()) {
                color++;
            }
        }
        if (color > max_color) {
            max_color = color;
        }

        p->neighbors.insert(color);

        if (n->children.size() > 0) {
            n->color = color;
            n->neighbors.insert(color);
            n->neighbors.insert(p->color);

            for (Node *c : n->children) {
                visit.push(c);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     nodes[i].print();
    //     cout << endl;
    // }
    // cout << max_color << endl;
    ofstream out("planting.out");
    out << max_color << endl;
    return 0;
}
