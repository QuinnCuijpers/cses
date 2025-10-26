#include <iostream>
#include <vector>
int main()
{
    size_t n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    long long total_cost = 0;

    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int cost = arr[i - 1] - arr[i];
            total_cost += cost;
            arr[i] += cost;
        }
    }

    std::cout << total_cost;
}