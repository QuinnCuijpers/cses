#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

void backtrack(std::string curr, std::string &source, std::map<char, size_t> &counter, std::vector<std::string> &seen)
{
    if (curr.size() == source.size())
    {
        seen.push_back(curr);
        // std::cout << curr << '\n';
        return;
    }

    std::map<char, size_t> curr_counter;

    for (auto kv : counter)
    {
        char c = kv.first;
        if (counter[c] == 0)
            continue;

        counter[c]--;
        curr += c;
        backtrack(curr, source, counter, seen);
        curr.pop_back();
        counter[c]++;
    }
}

int main()
{
    std::string str;
    std::cin >> str;

    std::sort(str.begin(), str.end());

    std::map<char, size_t> counter;

    for (auto c : str)
    {
        counter[c]++;
    }

    std::vector<std::string> seen;

    backtrack("", str, counter, seen);

    std::cout << seen.size() << '\n';
    for (auto s : seen)
    {
        std::cout << s << '\n';
    }
}