#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Event {
    int cow;
    bool start;
    int t;

};

bool event_sorter(const Event& lhs, const Event& rhs) {
    return lhs.t < rhs.t;
}

void event_print(Event& e) {
    std::cout << "cow: " << e.cow << ", t: " << e.t << ", start/end: " << e.start << std::endl;
}

void reserve(std::vector<int>& b, int cow, int n) {
    int i = 0;
    while (n > 0 && i < b.size()) {
        if (b[i] == -1) {
            n--;
            b[i] = cow;
        }
        i++;
    }

    if (n > 0) {
        for (int j = 0; j < n; j++) {
            b.push_back(cow);
        }
    }
}

void free(std::vector<int>& b, int cow) {
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == cow) b[i] = -1;
    }
}

int main()
{
    std::ifstream infile("blist.in");
    int n;
    infile >> n;

    int* s = new int[n];
    int* t = new int[n];
    int* b = new int[n];

    Event* events = new Event[n * 2];
    for (int i = 0; i < n; i++) {
        infile >> s[i] >> t[i] >> b[i];
        events[i * 2].cow = i;
        events[i * 2].start = true; 
        events[i * 2].t = s[i];
        events[i * 2 + 1].cow = i;
        events[i * 2 + 1].start = false; 
        events[i * 2 + 1].t = t[i];
    }

    std::sort(events, events + 2 * n, &event_sorter);

    std::vector<int> buckets;
    for (int i = 0; i < n * 2; i++) {
        Event& e = events[i];
        int cow = e.cow;
        if (e.start) {
            reserve(buckets, cow, b[cow]);
        } else {
            free(buckets, cow);
        }
    }
    // std::cout << buckets.size() << std::endl;

    std::ofstream outfile("blist.out");
    outfile << buckets.size() << std::endl;

    // std::cout << m[0] << ", " << m[1] << ", " << m[2] << std::endl;
    delete s;
    delete t;
    delete b;
    delete events;
    return 0;
}