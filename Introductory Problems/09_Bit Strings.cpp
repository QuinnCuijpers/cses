#include <iostream>
#include <cmath>

int main()
{
    long long n;
    std::cin >> n;

    long long result = 1;
    for (int i = 0; i < n; i++)
    {
        result = (result * 2) % ((int)pow(10, 9) + 7);
    }

    std::cout << result << std::endl;
}