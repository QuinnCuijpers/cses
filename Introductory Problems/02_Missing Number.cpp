#include <bits/stdc++.h>

int main()
{
    size_t n;
    std::cin >> n;
    std::vector<int> arr(n - 1);
    for (size_t i = 0; i < n - 1; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    for (size_t i = 0; i < n - 2; i++)
    {
        if (arr[i] + 1 != arr[i + 1])
        {
            std::cout << arr[i] + 1;
            std::exit(0);
        }
    }

    if (arr[0] != 1)
    {
        std::cout << 1;
    }
    else
    {
        std::cout << n;
    }
}