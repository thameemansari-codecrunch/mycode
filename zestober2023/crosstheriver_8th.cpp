
//Author:S.Thameem Ansari
//initializing  necessary header file
#include <iostream>
#include <vector>

bool can_jump(std::vector<int>& stones, int position, int jumps_left, int max_jump) {
    // if the current position is beyond the last stone,the toad has successfully crossed the river 
    if (position >= stones.size()) {
        return true;
    }
    //if there are no jump left the toad cannot proceed further
    if (jumps_left == 0) {
        return false;
    }
    for (int i = 0; i < std::min(max_jump, int(stones.size()) - position); i++) {
        if (can_jump(stones, position + i + 1, jumps_left - 1, max_jump)) {
            return true;
        }
    }
    //if no successfull jump is found return false
    return false;
}

bool can_cross_river(std::vector<int>& stones, int K, int L, int n_k, int n_l) {
    for (int i = 0; i < stones.size(); i++) {
        if (can_jump(stones, i, n_k, K) && can_jump(stones, i, n_l, L)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> stones = {0, 2, 4, 7, 9, 10, 12, 14, 15, 17, 19, 21, 23};
    int K = 2;
    int L = 5;
    int n_k = 4;
    int n_l = 3;
    bool result = can_cross_river(stones, K, L, n_k, n_l);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
