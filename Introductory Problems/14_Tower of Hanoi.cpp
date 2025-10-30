#include <iostream>
#include <cmath>

void hanoi_move(int src, int dst, int empty, int amount)
{
    if (amount == 1)
    {
        std::cout << src << " " << dst << std::endl;
        return;
    }
    if (amount > 1)
    {
        hanoi_move(src, empty, dst, amount - 1);
    }

    hanoi_move(src, dst, empty, 1);

    if (amount > 1)
    {
        hanoi_move(empty, dst, src, amount - 1);
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << (int)pow(2.0, n) - 1 << std::endl;
    hanoi_move(1, 3, 2, n);
}