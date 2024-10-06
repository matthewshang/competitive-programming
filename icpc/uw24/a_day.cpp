#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    ordered_set<int> st;
    map<int, int> counter_to_id;
    map<int, int> id_to_counter;
    int count = 1;

    auto new_problem = [&](int id) {
        counter_to_id[count] = id;
        id_to_counter[id] = count;
        st.insert(count);
        count++;
    };

    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        new_problem(id);
    }

    while (q--) {
        // while (true) {
        string event;
        cin >> event;
        if (event == "ToSolve") {
            int id;
            cin >> id;
            int this_counter = id_to_counter[id];
            st.erase(this_counter);
            counter_to_id.erase(this_counter);
            id_to_counter[id] = count;
            counter_to_id[count] = id;
            st.insert(count);
            count++;
        } else if (event == "IdAt") {
            int k;
            cin >> k;
            auto it = st.find_by_order(k - 1);
            int id = counter_to_id[*it];
            cout << id << "\n";
        } else if (event == "Kof") {
            int id;
            cin >> id;
            int pos = st.order_of_key(id_to_counter[id]) + 1;
            cout << pos << "\n";
        } else {
            int id;
            cin >> id;
            new_problem(id);
        }
    }

    return 0;
}
