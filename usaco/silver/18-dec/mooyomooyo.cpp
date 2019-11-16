#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <array>

template <typename T>
struct Board
{
    Board(int n) : r(n)
    {
        b = new T[r * 10];
        std::fill(b, b + r * 10, false);
    }

    ~Board()
    {
        delete b;
    }

    T get(int y, int x)
    {
        return b[y * 10 + x];
    }

    void set(int y, int x, T val)
    {
        b[y * 10 + x] = val;
    }

    void print()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                std::cout << get(i, j);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void write(const std::string &path)
    {
        std::ofstream out(path);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                out << get(i, j);
            }
            out << std::endl;
        }
    }

    int r;

  private:
    T *b;
};

typedef std::vector<std::pair<int, int>> vc;
void flood(int row, int col, int color, Board<int> &b, Board<bool> &mark, vc &p)
{
    if (row < 0 || row >= b.r || col < 0 || col >= 10 || b.get(row, col) != color || mark.get(row, col))
    {
        return;
    }

    p.push_back(std::make_pair(row, col));
    mark.set(row, col, true);
    flood(row + 1, col, color, b, mark, p);
    flood(row - 1, col, color, b, mark, p);
    flood(row, col + 1, color, b, mark, p);
    flood(row, col - 1, color, b, mark, p);
}

typedef std::array<std::vector<vc>, 10> region_map;
region_map find_regions(Board<int> &b, int k)
{
    region_map regions;
    Board<bool> mark(b.r);
    for (int row = 0; row < b.r; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (mark.get(row, col))
                continue;
            int c = b.get(row, col);
            if (c == 0)
                continue;

            vc p;
            flood(row, col, c, b, mark, p);
            if (p.size() >= k) regions[c].push_back(p);
        }
    }
    return regions;
}

int shift(Board<int> &b, int start, int col, int off)
{
    int i = 0;
    while (b.get(start, col) != 0 && start >= 0)
    {
        if (off != 0)
        {
            b.set(start + off, col, b.get(start, col));
            b.set(start, col, 0);
        }
        start--;
        i++;
    }
    return i;
}

void gravity2(Board<int> &b)
{
    for (int col = 0; col < 10; col++)
    {
        int row = b.r - 1;
        while (row >= 0)
        {
            int off = 0;
            while (b.get(row, col) == 0 && row >= 0)
            {
                row--;
                off++;
            }
            // std::cout << row << std::endl;

            if (row == -1)
                break;

            row -= shift(b, row, col, off);
        }
    }
}

void gravity(Board<int> &b)
{
    for (int col = 0; col < 10; col++)
    {
        int i = b.r - 1;
        while (i >= 0 && b.get(i, col) != 0)
        {
            i--;
        }
        if (i == -1) continue;

        int j = i;
        while (i >= 0)
        {
            while (j >= 0 && b.get(j, col) == 0)
            {
                j--;
            }
            if (j == -1) break;

            b.set(i, col, b.get(j, col));
            b.set(j, col, 0);
            i--;
        }
    }
}
int main()
{
    std::ifstream input("mooyomooyo.in");
    int n, k;
    input >> n >> k;

    Board<int> b(n);
    for (int r = 0; r < n; r++)
    {
        std::string line;
        input >> line;
        for (int c = 0; c < 10; c++)
        {
            b.set(r, c, line[c] - '0');
        }
    }

    while (true)
    {
        gravity(b);
        b.print();

        region_map regions = find_regions(b, k);
        int count = 0;

        for (int i = 0; i < 10; i++)
        {
            auto &r = regions[i];
            std::cout << i << ": ";
            for (vc &v : r)
            {
                count++;
                for (auto &pair : v)
                {
                    b.set(pair.first, pair.second, 0);
                }
                std::cout << v.size() << ", ";
            }
            std::cout << std::endl;
        }
        if (count == 0)
            break;
    }

    b.write("mooyomooyo.out");

    return 0;
}