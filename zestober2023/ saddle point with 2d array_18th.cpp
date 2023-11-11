
//Author:S.Thameem Ansari
//Including necessary header file 
#include <iostream>
#include <vector>
using namespace std;
 
pair<int, int> find_saddle_point(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        int min_in_row = matrix[i][0];
        int min_index = 0;
 
        // Find the minimum element in the row and its index
        for (int j = 1; j < matrix[i].size(); j++) {
            if (matrix[i][j] < min_in_row) {
                min_in_row = matrix[i][j];
                min_index = j;
            }
        }
 
        // Check if the minimum element in the row is also the maximum in its column
        bool is_saddle_point = true;
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[j][min_index] > min_in_row) {
                is_saddle_point = false;
                break;
            }
        }
 
        // If it's a saddle point, return its coordinates
        if (is_saddle_point) {
            return make_pair(i, min_index);
        }
    }
 
    // If no saddle point is found, return (-1, -1)
    return make_pair(-1, -1);
}
 
int main() {
    vector<vector<int>> matrix = {
        {9, 8, 7},
        {5, 3, 2},
        {6, 6, 7}
    };
    pair<int, int> result = find_saddle_point(matrix);
    cout << "Output - (" << result.first << ", " << result.second << ")" << endl;
    return 0;
}
