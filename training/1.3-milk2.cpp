/*
ID: mshang41
LANG: C++14
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ifstream infile("milk2.in");
    int N;
    infile >> N;

    std::vector<std::pair<int, bool>> times;
    std::vector<int> starts;
    std::vector<int> ends;
    int s, e;
    while (infile >> s >> e) {
        auto it = std::find(starts.begin(), starts.end(), e);
        if (it != starts.end()) {
            starts.erase(it);
        } else {
            ends.push_back(e);
        }

        it = std::find(ends.begin(), ends.end(), s);
        if (it != ends.end()) {
            ends.erase(it);
        } else {
            starts.push_back(s);
        }
    }

    for (int i = 0; i < starts.size(); i++) {
        times.push_back(std::make_pair(starts[i], true));
    }
    for (int i = 0; i < ends.size(); i++) {
        times.push_back(std::make_pair(ends[i], false));
    }
    std::sort(times.begin(), times.end());

    for (int i = 0; i < times.size(); i++) {
        std::cout << "t: " << times[i].first << ", start: " << times[i].second << std::endl; 
    }

    int longestMilk = 0;
    int longestIdle = 0;
    int current = 0;
    for (int i = 0; i < times.size() - 1; i++) {
        auto &pair = times[i];
        if (pair.second) current++;
        else current--;

        if (pair.second) {
            int local = current;
            int j = i;
            while (j < times.size() && local > 0) {
                j++;
                if (times[j].second) local++;
                else local--; 
            }
            int d = times[j].first - pair.first;
            if (d > longestMilk) {
                longestMilk = d;
            }
        } else {
            int local = current;
            int j = i;
            while (j < times.size() && local == 0) {
                j++;
                if (times[j].second) local++;
                else local--; 
            }
            int d = times[j].first - pair.first;
            if (d > longestIdle) {
                longestIdle = d;
            }
        }
    }

    std::cout << longestMilk << ", " << longestIdle << std::endl;

    std::ofstream out("milk2.out");
    out << longestMilk << " " << longestIdle << std::endl;

    return 0;
}