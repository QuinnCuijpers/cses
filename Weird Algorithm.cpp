#include <iostream>

long long weirdAlgo(long long n)
{

    if (n % 2 == 0)
    {
        n = (n / 2);
    }
    else
    {
        n = (3 * n + 1);
    }
    return n;
}

int main()
{
    int n;
    long long res = -1;
    std::cin >> n;

    if (n == 1)
    {
        std::cout << 1 << " ";
        std::exit(0);
    }

    std::cout << n << " ";
    res = weirdAlgo(n);
    while (res != 1)
    {
        std::cout << res << " ";
        res = weirdAlgo(res);
    }
    std::cout << 1 << " ";
    return 0;
}