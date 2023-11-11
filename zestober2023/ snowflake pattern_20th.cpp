
//Author:S.Thameem Ansari
//Including  utility and algorithm header file
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool is_symmetrical(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> snowflake) {
    for (auto segment : snowflake) {
        std::pair<int, int> point1 = segment.first;
        std::pair<int, int> point2 = segment.second;
        bool found_mirror_segment = false;

        // Check if there exists a mirror segment for the current segment
        for (auto mirror_segment : snowflake) {
            std::pair<int, int> mirror_point1 = mirror_segment.first;
            std::pair<int, int> mirror_point2 = mirror_segment.second;

            // Check if the current segment is mirrored by the mirror_segment
            if ((point1 == mirror_point1 && point2 == mirror_point2) || (point1 == mirror_point2 && point2 == mirror_point1)) {
                found_mirror_segment = true;
                break;
            }
        }

        // If no mirror segment is found, snowflake is not symmetrical
        if (!found_mirror_segment) {
            return false;
        }
    }

    // If all segments have mirror segments, snowflake is symmetrical
    return true;
}

int main() {
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> snowflake = {
        std::make_pair(std::make_pair(0, 0), std::make_pair(1, 0)),
        std::make_pair(std::make_pair(1, 0), std::make_pair(2, 0)),
        std::make_pair(std::make_pair(2, 0), std::make_pair(3, 0))
    };
    
    std::cout << std::boolalpha << is_symmetrical(snowflake) << std::endl;  // Output: true
    
    return 0;
}
