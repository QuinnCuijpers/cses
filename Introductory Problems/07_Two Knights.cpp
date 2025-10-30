
#include <iostream>

void solve(long long n)
{
    // the amount of ways of placing two knights on a
    // n x n grid is n^2 choose 2. Then remove the 2 illegal combinations
    // for every 3x2 box and 2x3 box, where the knights attack eachother

    if (n == 1)
    {
        std::cout << 0 << std::endl;
        return;
    }

    if (n == 2)
    {
        std::cout << 6 << std::endl;
        return;
    }

    long long total_placements = n * n * (n * n - 1) / 2;
    long long amount_of_horizontal_boxes = (n - 2) * (n - 1);
    long long amount_of_vertical_boxes = (n - 1) * (n - 2);
    long long result =
        total_placements -
        2 *
            (amount_of_horizontal_boxes + amount_of_vertical_boxes);
    std::cout << result << std::endl;
}

int main()
{
    long long n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        solve(i);
    }
}