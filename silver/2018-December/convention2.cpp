#include "bits/stdc++.h"

using namespace std;

priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > events, waiting;
// events format: arrival, duration, rank
//     duration < 0 if it is ending, = original arrival * -1
// waiting format: rank, arrival, duration
int max_wait = 0;

void update(const array<int, 3>& ev) {
    auto& next = waiting.top();
    cout << "Update: " << ev[0] << " " << ev[1] << ", " << next[1] << endl;
    int d = ev[0] - next[1]; 
    if (d > max_wait) max_wait = d;

    events.push({ev[0] + next[2], 0, next[0]});
    waiting.pop();
}

int main()
{
    ifstream input("convention2.in");
    ofstream output("convention2.out");

    int n;
    input >> n;

    for (int i = 0; i < n; i++) {
        int a, t;
        input >> a >> t;
        events.push({a, t, i});
    }
    // while (events.size()) {
    //     auto& ev = events.top();
    //     cout << "a: " << ev[0] << " t: " << ev[1] << " rank: " << ev[2] << endl;
    //     events.pop();
    // }

    bool occupied = false;
    while (events.size()) {
        auto& ev = events.top();
        cout << "Event - time: " << ev[0] << " duration: " << ev[1] << " rank: " << ev[2] << endl;
        // if t == 0, it is an end event
        if (ev[1] == 0) {
            if (waiting.empty()) {
                occupied = false;
            } else {
                update(ev);
                occupied = true;
            }
        } else {
            waiting.push({ev[2], ev[0], ev[1]});
            if (!occupied) {
                update(ev);
                occupied = true;
            }
        }        
        events.pop();
    }
    cout << max_wait << endl;
    output << max_wait;

    return 0;
}