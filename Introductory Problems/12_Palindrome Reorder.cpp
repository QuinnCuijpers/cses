#include <iostream>
#include <fstream>
#include <unordered_map>

bool is_palindrome(std::string s)
{
    int n = s.size();
    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string s;
    std::unordered_map<char, int> counter;

    // std::ifstream in_file;
    // in_file.open("./test_input.txt");
    // std::getline(in_file, s);
    // in_file.close();

    std::getline(std::cin, s);

    for (auto c : s)
    {
        counter[c] += 1;
    }

    int amount_of_uneven_appearances = 0;

    for (auto c : counter)
    {
        if (c.second % 2 == 1)
        {
            amount_of_uneven_appearances += 1;
        }
    }

    if (amount_of_uneven_appearances > 1)
    {
        std::cout << "NO SOLUTION";
        exit(0);
    }

    std::string solution = s;

    size_t palindrome_index = 0;

    for (auto c : counter)
    {
        char key = c.first;
        int val = c.second;

        // std::cout << key << " " << val << std::endl;

        if (val % 2 == 0)
        {
            std::string new_substring = std::string(val / 2, key);

            solution.replace(palindrome_index, val / 2, new_substring);
            solution.replace(solution.size() - palindrome_index - val / 2, val / 2, new_substring);
            palindrome_index += val / 2;
        }
        else
        {
            solution.replace((solution.size() - 1) / 2 - val / 2, val, std::string(val, key));
        }
    }
    std::cout << solution << std::endl;
    // std::cout << is_palindrome(solution) << std::endl;
}