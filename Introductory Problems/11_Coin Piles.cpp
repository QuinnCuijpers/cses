#include <iostream>

bool solvable(int a, int b)
{
    // assume a = 2k+l and b=2l+k
    // b = 2l+k => k = b-2l
    // thus a = 2k+l
    // = 2(b-2l) + l
    // = 2b - 3l
    // solving for l gives l = (2b-a)/3.
    // If l is an integer than a solution to the coin problem exists
    // if (2b-a) is a multiple of 3 then l is an integer.
    // Then check k and l are positive.

    if ((2 * b - a) % 3 == 0)
    {
        int l = (2 * b - a) / 3;
        int k = b - 2 * l;

        return l >= 0 && k >= 0;
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    int a, b;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> a >> b;
        if (solvable(a, b))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
}