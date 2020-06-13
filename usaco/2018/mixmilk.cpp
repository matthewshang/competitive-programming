#include <iostream>
#include <fstream>

int main()
{

    std::ifstream infile("mixmilk.in");
    int c[3] = {};
    int m[3] = {};
    infile >> c[0] >> m[0] >> c[1] >> m[1] >> c[2] >> m[2];

    for (int i = 0; i < 100; i++)
    {
        int j = i % 3;
        int k = (j + 1) % 3;
        m[k] += m[j];
        m[j] = 0;
        if (m[k] > c[k])
        {
            m[j] = m[k] - c[k];
            m[k] = c[k];
        }
    }

    std::ofstream outfile("mixmilk.out");
    outfile << m[0] << std::endl << m[1] << std::endl << m[2] << std::endl;

    // std::cout << m[0] << ", " << m[1] << ", " << m[2] << std::endl;
    return 0;
}