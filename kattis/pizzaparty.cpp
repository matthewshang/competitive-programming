#include "bits/stdc++.h"
using namespace std;

/* Date: 2022-01-26
 * Source: ICPC NAQ 2021
 * Summary: Build a graph such that "or" statements are edges from the conditional
 * toppings to the implicative topping and "and" statements are similar except
 * the conditional toppings point to a fake topping that points to the real topping
 * with an "or" edge. Then run something similar to topological sort starting
 * from the absolute preferences.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    map<string, vector<pair<string, bool>>> g;
    map<string, int> deg;
    map<string, int> occur;
    set<string> fake;
    for (int i = 0; i < c; i++) {
        string token;
        cin >> token;

        if (token == "if") {
            string top;
            vector<string> tops;
            bool anded = true;
            while (token != "then") {
                cin >> top >> token;
                tops.push_back(top);
                if (token == "or") {
                    anded = false;
                }
            }
            cin >> top;
            occur[top]++;
            if (anded) {
                string target = top + to_string(occur[top]);
                fake.insert(target);
                for (const auto& t : tops) {
                    g[t].push_back({target, true});
                    deg[target]++;
                }
                g[target].push_back({top, false});
            } else {
                for (const auto& t : tops) {
                    g[t].push_back({top, false});
                }
            }
        } else {
            g["$"].push_back({token, false});
        }
    }
    fake.insert("$");

    set<string> seen;
    queue<string> q({"$"});
    int visited = 0;
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        if (fake.find(cur) == fake.end()) {
            visited++;
        }

        for (const auto& next : g[cur]) {
            if (next.second) {
                // and edge
                if (--deg[next.first] == 0 && seen.find(next.first) == seen.end()) {
                    q.push(next.first);
                    seen.insert(next.first);
                } 
            } else if (seen.find(next.first) == seen.end()) {
                // or edge
                q.push(next.first);
                seen.insert(next.first);
            }
        }
    }
    cout << visited << '\n';

    return 0;
}