
#include <iostream>
#include <vector>

int main()
{
    long long n;
    std::cin >> n;

    long long total_sum = n * (n + 1) / 2;
    long long half_sum_floored = total_sum / 2LL;
    double half_sum = static_cast<double>(total_sum) / 2LL;

    // std::cout << total_sum << std::endl;
    // std::cout << half_sum_floored << std::endl;

    if (half_sum_floored != half_sum)
    {
        std::cout << "NO";
        exit(0);
    }

    std::cout << "YES" << std::endl;

    std::vector<int> s_1;
    std::vector<int> s_2;

    for (long long i = n; i > 0; i--)
    {
        if (half_sum_floored >= i)
        {
            s_1.push_back(i);
            half_sum_floored -= i;
        }
        else
        {
            s_2.push_back(i);
        }
    }

    std::cout << s_1.size() << std::endl;
    for (auto c : s_1)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << s_2.size() << std::endl;
    for (auto c : s_2)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}