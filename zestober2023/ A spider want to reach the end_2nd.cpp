
//Author:S.Thameem Ansari
//including necessary header file
// isSafe:This function checks if a given cell in the grid is safe to move
//canReachEnd:This recursive function uses Depth-First Search (DFS) to explore the grid
//It starts from the top-left corner and explores down and right directions
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>>& grid, int row, int col) { 
    int numRows = grid.size();
    int numCols = grid[0].size();
    return (row >= 0 && row < numRows && col >= 0 && col < numCols && grid[row][col] == 0);
}

bool canReachEnd(vector<vector<int>>& grid, int row, int col) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    // If spider reaches the bottom-right corner, return true
    if (row == numRows - 1 && col == numCols - 1) {
        return true;
    }

    // Mark the current cell as visited
    grid[row][col] = 1;

    // Explore down and right directions
    if (isSafe(grid, row + 1, col) && canReachEnd(grid, row + 1, col)) {
        return true;
    }
    if (isSafe(grid, row, col + 1) && canReachEnd(grid, row, col + 1)) {
        return true;
    }

    // If there is no valid path from this cell, backtrack and mark it as unvisited
    grid[row][col] = 0;

    return false;
}

bool canSpiderReachEnd(vector<vector<int>>& grid) {
    // Check if spider can reach the bottom-right corner starting from the top-left corner
    return canReachEnd(grid, 0, 0);
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 0}
    };

    if (canSpiderReachEnd(grid)) {
        cout << "Spider can reach the end it is true." << endl;
    } else {
        cout << "Spider cannot reach the end it is false." << endl;
    }

    return 0;
}
