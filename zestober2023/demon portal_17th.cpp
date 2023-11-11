
//Author:S.Thameem Ansari
// this program identifies demon portal on a 2d grid a score them based on near by demon portals
//Including necessary header
#include <iostream>
#include <vector>
std::vector<std::pair<std::pair<int, int>, int>> score_demon_portals(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::pair<std::pair<int, int>, int>> scores;
auto count_nearby_portals = [&](int row, int col) {
        int count = 0;
        for (int i = std::max(0, row - 1); i < std::min(rows, row + 2); i++) {
            for (int j = std::max(0, col - 1); j < std::min(cols, col + 2); j++) {
                if (grid[i][j] == 1 && !(i == row && j == col)) {
                    count += 1;
                }
            }
        }
        return count;
    };
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                int portal_score = count_nearby_portals(i, j);
                scores.push_back(std::make_pair(std::make_pair(i, j), portal_score));
            }
        }
    }
    
    return scores;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };
std::vector<std::pair<std::pair<int, int>, int>> output = score_demon_portals(grid);
for (auto& score : output) {
        std::cout << "(" << score.first.first << ", " << score.first.second << "): " << score.second << std::endl;
    }
    
    return 0;
}
