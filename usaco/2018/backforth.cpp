#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

typedef std::vector<int> vi;

void read(vi &b1, vi &b2)
{
    std::ifstream infile("backforth.in");
    for (int i = 0; i < 10; i++)
    {
        int s;
        infile >> s;
        b1.push_back(s);
    }
    for (int i = 0; i < 10; i++)
    {
        int s;
        infile >> s;
        b2.push_back(s);
    }
}

void print_set(std::set<int> &p)
{
    for (int i : p)
    {
        std::cout << i << std::endl;
    }
}

void sim2(vi &x1, vi &x2, int m1, int m2, int depth, int max, std::set<int> &p)
{
    if (depth >= max)
    {
        p.insert(depth % 2 == 0 ? m2 : m1);
        return;
    }

    std::set<int> tried;
    for (int i = 0; i < x1.size(); i++)
    {
        int c = x1[i];
        if (tried.find(c) != tried.end())
        {
            continue;
        }
        else
        {
            tried.insert(c);
        }

        vi b1 = x1;
        vi b2 = x2;
        b2.push_back(c);
        b1.erase(b1.begin() + i);
        sim2(b2, b1, m2 - c, m1 + c, depth + 1, max, p);
    }
}

void sim(vi &x1, vi &x2, int m1, int m2, int depth, int max, std::set<int> &p)
{
    if (depth >= max)
    {
        p.insert(m1);
        return;
    }

    if (depth % 2 == 0)
    {
        // Tank 1 -> Tank 2
        std::set<int> tried;
        for (int i = 0; i < x1.size(); i++)
        {
            int c = x1[i];
            if (tried.find(c) != tried.end())
            {
                continue;
            }
            else
            {
                tried.insert(c);
            }

            vi b1 = x1;
            vi b2 = x2;
            b2.push_back(c);
            b1.erase(b1.begin() + i);
            sim(b1, b2, m1 - c, m2 + c, depth + 1, max, p);
        }
    }
    else
    {
        // Tank 2 -> Tank 1;
        std::set<int> tried;
        for (int i = 0; i < x2.size(); i++)
        {
            int c = x2[i];
            if (tried.find(c) != tried.end())
            {
                continue;
            }
            else
            {
                tried.insert(c);
            }

            vi b1 = x1;
            vi b2 = x2;
            b1.push_back(c);
            b2.erase(b2.begin() + i);
            sim(b1, b2, m1 + c, m2 - c, depth + 1, max, p);
        }
    }
}

int main()
{
    vi b1;
    vi b2;
    read(b1, b2);
    std::set<int> p;

    sim2(b1, b2, 1000, 1000, 0, 4, p);
    print_set(p);
    std::ofstream outfile("backforth.out");
    outfile << p.size() << std::endl;
    return 0;
}