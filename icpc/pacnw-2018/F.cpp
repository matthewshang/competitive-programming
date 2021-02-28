#include "bits/stdc++.h"
 
using namespace std;
 
struct seg_node {
    seg_node *left, *right;
    int sum;
    bool toggle, lazy;
 
    seg_node() : sum{0}, left{nullptr}, right{nullptr}, toggle{false}, lazy{false} {}
 
    void mark() {
        lazy ^= true;
    }
 
    void push(int L, int R) {
        if (lazy != toggle) {
            if (L != R) {
                if (!left) left = new seg_node();
                left->mark();
                if (!right) right = new seg_node();
                right->mark();
            }
            sum = R - L + 1 - sum;
            toggle = lazy;
        }
    }
 
    void flip(int lo, int hi, int L, int R) {
        push(L, R);
        if (hi < L || lo > R) return;
        if (lo <= L && R <= hi) {
            mark();
            push(L, R);
        } else {
            int M = L + (R - L) / 2;
            if (!left) left = new seg_node();
            left->flip(lo, hi, L, M);
            if (!right) right = new seg_node();
            right->flip(lo, hi, M + 1, R);
            sum = left->sum + right->sum;
        }
    }
};
 
struct event {
    int time, a, b;
    bool operator<(const event& e) const {
        return time < e.time;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
    vector<event> evs;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        evs.push_back({ x1, y1, y2 - 1 });
        evs.push_back({ x2, y1, y2 - 1 });
    }
    sort(evs.begin(), evs.end());
 
    constexpr int M = (1 << 30) - 1;
    seg_node* root = new seg_node();
    long long area = 0;
    int last_time = evs[0].time;
    for (const event& e : evs) {
        int on = root->sum;
        area += (long long)on * (e.time - last_time);
        last_time = e.time;
        root->flip(e.a, e.b, 0, M);
    }
    cout << area << '\n';
 
    return 0;
}