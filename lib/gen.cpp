#include "bits/stdc++.h"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
};

int main() {

    return 0;
}