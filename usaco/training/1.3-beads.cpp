/*
ID: mshang41
LANG: C++14
TASK: beads
*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

std::string rotate(std::string s, int n)
{
    std::rotate(s.begin(), s.begin() + n, s.end());
    return s;
}

int breakLace(int N, std::string &lace, int s)
{
    char color = 'n';
    int size = 0;
    std::string rotated = rotate(lace, s);
    std::vector<bool> collected(N);

    for (int i = 0; i < N; i++)
    {
        char bead = rotated[i];
        if (collected[i]) break;
        if (bead != 'w')
        {
            if (color == 'n')
            {
                color = bead;
            }
            else
            {
                if (color != bead)
                    break;
            }
        }
        size++;
        collected[i] = true;
    }

    color = 'n';
    for (int i = N - 1; i >= 0; i--)
    {
        char bead = rotated[i];
        if (collected[i]) break;
        if (bead != 'w')
        {
            if (color == 'n')
            {
                color = bead;
            }
            else
            {
                if (color != bead)
                    break;
            }
        }
        size++;
        collected[i] = true;
    }
    return size;
}

int main()
{
    std::ifstream in("beads.in");
    int N;
    std::string necklace;    
    in >> N;
    in >> necklace;

    // necklace = "rrr";
    // N = necklace.length();    

    int maxSize = -1;
    for (int i = 0; i <= N; i++)
    {
        int size = breakLace(N, necklace, i);
        // std::cout << size << std::endl;
        if (size > maxSize)
            maxSize = size;
    }
    std::ofstream out("beads.out");
    out << maxSize << std::endl;
    // std::cout << maxSize << std::endl;
}
