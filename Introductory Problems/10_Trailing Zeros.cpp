#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    long long trailing_zeros = 0;

    for (int i = 1; i < n; i++)
    {
        if (n / (int)pow(5, i) != 0)
        {
            trailing_zeros += n / (int)pow(5, i);
        }
        else
        {
            break;
        }
    }

    std::cout << trailing_zeros;
}