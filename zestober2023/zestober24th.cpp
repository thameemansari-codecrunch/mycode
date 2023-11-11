
//Author:S.Thameem Ansari
//Including necessary header file 
//the actually output is 3 but my output is 4 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int regulate_water_levels(vector<vector<int>>& city_map) {
    int count = 0;
    int rows = city_map.size();
    int cols = city_map[0].size();
    for (int i = 0; i < rows - 1; i += 2) {
        for (int j = 0; j < cols - 1; j += 2) {
            vector<int> grid = {city_map[i][j], city_map[i][j + 1], city_map[i + 1][j], city_map[i + 1][j + 1]};
            int max_level = *max_element(grid.begin(), grid.end());
            if (max_level > 10) {
                int diff = max_level - 10;
                count += 1;
                for (int x = i; x < i + 2; x++) {
                    for (int y = j; y < j + 2; y++) {
                        city_map[x][y] -= diff;
                        if (city_map[x][y] < 0) {
                            city_map[x][y] = 0;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> city_map = {{11, 12, 7, 9}, {15, 8, 13, 11}, {7, 8, 12, 6}, {14, 10, 5, 9}};
    int result = regulate_water_levels(city_map);
    cout << "Number of regions still prone: " << result << endl;
    return 0;
}
