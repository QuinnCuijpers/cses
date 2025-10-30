
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> gray_code;

void prepend(gray_code &arr, std::string c)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        arr[i].insert(0, c);
    }
}

gray_code generate_gray_code(int n)
{
    gray_code G1 = {"0", "1"};
    gray_code result = G1;
    for (int i = 0; i < n - 1; ++i)
    {
        gray_code old = result;
        gray_code _new = result;
        std::reverse(_new.begin(), _new.end());
        prepend(old, "0");
        prepend(_new, "1");

        old.insert(old.end(), _new.begin(), _new.end());
        result = old;
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    gray_code res = generate_gray_code(n);
    for (auto b : res)
    {
        std::cout << b << std::endl;
    }
}