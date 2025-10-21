#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    long long total_cost = 0;

    for (int i = 1; i < n; i++)
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