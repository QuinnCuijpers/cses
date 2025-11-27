#include <iostream>
#include <vector>

constexpr int GRID_SIZE{8};
std::vector<int> column(GRID_SIZE);
std::vector<int> diag1((GRID_SIZE * GRID_SIZE));
std::vector<int> diag2((GRID_SIZE * GRID_SIZE));
int count{};

void search(std::vector<std::vector<char>> &grid, size_t row)
{
    if (row == GRID_SIZE)
    {
        ++count;
        return;
    }
    for (size_t col = 0; col < GRID_SIZE; ++col)
    {
        if (column[col] || diag1[row + col] || diag2[col - row + GRID_SIZE - 1] || grid[row][col] == '*')
            continue;
        column[col] = diag1[col + row] = diag2[col - row + GRID_SIZE - 1] = 1;
        search(grid, row + 1);
        column[col] = diag1[col + row] = diag2[col - row + GRID_SIZE - 1] = 0;
    }
}

int main()
{
    std::vector<std::vector<char>> grid(GRID_SIZE, std::vector<char>(GRID_SIZE));

    for (size_t i = 0; i < GRID_SIZE; ++i)
    {
        for (size_t j = 0; j < GRID_SIZE; ++j)
        {
            std::cin >> grid[i][j];
        }
    }
    search(grid, 0);
    std::cout << count << '\n';
}