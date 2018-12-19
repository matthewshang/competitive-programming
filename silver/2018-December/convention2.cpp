#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <functional>

struct Cow
{
    int rank;
    int a;
    int t;

    bool operator<(const Cow &c) const
    {
        return rank > c.rank;
    }
};

struct Event
{
    Event(int _time, Cow &_c, bool _s) : time(_time), c(_c), start(_s) {}
    int time;
    Cow &c;
    bool start;

    bool operator<(const Event &e) const
    {
        return time < e.time;
    }
};

bool cow_compare(const Cow &lhs, const Cow &rhs)
{
    return lhs.a < rhs.a;
}

int main()
{
    std::ifstream input("convention2.in");
    int n;
    input >> n;
    Cow *cows = new Cow[n];
    for (int i = 0; i < n; i++)
    {
        int a, t;
        input >> a >> t;
        cows[i].rank = i;
        cows[i].a = a;
        cows[i].t = t;
    }
    std::sort(cows, cows + n, &cow_compare);

    std::priority_queue<Cow> q;
    std::priority_queue<Event> events;

    bool occupied = false;
    for (int i = 0; i < n; i++)
    {
        events.emplace(cows[i].a, cows[i], true);
    }

    Cow *current = nullptr;
    while (!events.empty())
    {
        const Event &e = events.top();
        if (e.start)
        {
            q.push(e.c);
        }
        else
        {
            const Cow &best = q.top();

            q.pop();
        }
        events.pop();
    }

    delete cows;
    return 0;
}