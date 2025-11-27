#include <iostream>
#include <vector>

void solve(size_t curr_index, long long subset_sum, std::vector<long long> &best_diff, long long sum, std::vector<long long> &weights)
{
    if (curr_index == weights.size())
        return;

    long long subset_sum2 = sum - subset_sum;

    long long diff{};
    if (subset_sum2 > subset_sum)
    {
        diff = subset_sum2 - subset_sum;
    }
    else
    {
        diff = subset_sum - subset_sum2;
    }

    best_diff[0] = std::min(best_diff[0], diff);

    solve(curr_index + 1, subset_sum, best_diff, sum, weights);
    subset_sum += weights[curr_index + 1];
    solve(curr_index + 1, subset_sum, best_diff, sum, weights);
    subset_sum -= weights[curr_index + 1];
}

int main()
{
    size_t n;
    long long sum{};
    std::vector<long long> apple_weights;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        long long apple_weight;
        std::cin >> apple_weight;
        apple_weights.push_back(apple_weight);
        sum += apple_weights[i];
    }

    std::vector<long long> best_diff{};
    best_diff.push_back(sum);

    solve(0, 0, best_diff, sum, apple_weights);
    std::cout << best_diff[0] << '\n';
}