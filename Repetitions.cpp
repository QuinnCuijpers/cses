#include <bits/stdc++.h>
int main()
{
    std::string s;
    getline(std::cin, s);

    int longest_count = 1;
    int current_count = 1;
    char current_char = s[0];
    for (size_t i = 1; i < s.length(); i++)
    {
        if (s[i] == current_char)
        {
            current_count++;
        }
        else
        {
            current_char = s[i];
            longest_count = std::max(current_count, longest_count);
            current_count = 1;
        }
    }
    longest_count = std::max(longest_count, current_count);

    std::cout << longest_count;
}