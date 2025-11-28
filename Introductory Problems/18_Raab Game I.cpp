#include <iostream>
#include <vector>

void print_vec(std::vector<int> &vec)
{
    for (auto c : vec)
    {
        std::cout << c << " ";
    }
    std::cout << '\n';
}

void solve(size_t n, size_t a, size_t b)
{
    std::vector<int> p1(n);
    std::vector<int> p2(n);
    if (a + b > n)
    {
        std::cout << "NO" << '\n';
        return;
    }

    if ((a == 0 || b == 0) && (a != b))
    {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';

    size_t e = n - (a + b);

    // start by making both series be n..n-e
    for (size_t i = 0; i < e; ++i)
    {
        p1[i] = static_cast<int>(n - i);
        p2[i] = static_cast<int>(n - i);
    }

    // next a values, ascending for p1, ascending but shifted by a for p2
    for (size_t i = 0; i < b; ++i)
    {
        size_t idx = e + i;
        p1[idx] = static_cast<int>(i + 1);
        p2[idx] = static_cast<int>(i + a + 1);
    }

    for (size_t i = 0; i < a; ++i)
    {
        size_t idx = e + b + i;
        p1[idx] = static_cast<int>(b + i + 1);
        p2[idx] = static_cast<int>(i + 1);
    }

    print_vec(p1);
    print_vec(p2);
}

int main()
{
    int t{};
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        size_t n;
        size_t a, b;
        std::cin >> n >> a >> b;
        solve(n, a, b);
    }
}