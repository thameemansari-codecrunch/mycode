
//Author:S.Thameem Ansari
//Including necessary header file   
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> find_chain_pairs(std::vector<int> chain_lengths, int target_length) {
    std::vector<std::vector<int>> chain_combinations;
    std::sort(chain_lengths.begin(), chain_lengths.end());

    for (int i = 0; i < chain_lengths.size(); i++) {
        int left = i + 1;
        int right = chain_lengths.size() - 1;

        while (left < right) {
            int total_length = chain_lengths[i] + chain_lengths[left] + chain_lengths[right];
            if (total_length == target_length) {
                chain_combinations.push_back({chain_lengths[i], chain_lengths[left], chain_lengths[right]});
                left++;
                right--;
                // Skip duplicates
                while (left < right && chain_lengths[left] == chain_combinations.back()[1]) {
                    left++;
                }
                while (left < right && chain_lengths[right] == chain_combinations.back()[2]) {
                    right--;
                }
            } else if (total_length < target_length) {
                left++;
            } else {
                right--;
            }
        }
        // Skip duplicates
        while (i + 1 < chain_lengths.size() && chain_lengths[i] == chain_lengths[i + 1]) {
            i++;
        }
    }
    return chain_combinations;
}

int main() {
    std::vector<int> chain_lengths = {4, 7, 2, 15, 1, 6, 9, 3};
    int target_length = 20;
    std::vector<std::vector<int>> result = find_chain_pairs(chain_lengths, target_length);

    for (const auto& combination : result) {
        for (int length : combination) {
            std::cout << length << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
