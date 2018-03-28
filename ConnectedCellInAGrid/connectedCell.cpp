#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int explore(int row, int col, int rows, int cols, std::vector<std::vector<int>>& grid) {
    // Make sure we are in range and that the cell is a 1
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) {
        return 0;
    }
    // Set the visited square equal to 0 and branch out in all directions
    grid[row][col] = 0;
    return 1 + 
            explore(row + 1, col + 1, rows, cols, grid) + 
            explore(row + 1, col, rows, cols, grid) +
            explore(row + 1, col - 1, rows, cols, grid) + 
            explore(row, col + 1, rows, cols, grid) +
            explore(row, col - 1, rows, cols, grid) + 
            explore(row - 1, col + 1, rows, cols, grid) +
            explore(row - 1, col, rows, cols, grid) + 
            explore(row - 1, col - 1, rows, cols, grid);
}

int get_biggest_region(std::vector<std::vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int max_block = 0;
    int current_block = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            // Current square has not been explored, so add it
            if (grid[row][col] == 1) {
                current_block = explore(row, col, rows, cols, grid);
                if (current_block > max_block) {
                    max_block = current_block;
                }
            }
        }
    }
    return max_block;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int grid_i = 0; grid_i < n; grid_i++) {
        for (int grid_j = 0; grid_j < m; grid_j++) {
            cin >> grid[grid_i][grid_j];
        }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
