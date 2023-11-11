
//Author:S.Thameem Ansari
//initializing necessary header file
#include <iostream>
#include <vector>
std::pair<int, int> calculate_max_enemies(std::vector<int> strengths, int initial_dagger_power, int increase_rate, int decrease_rate) {
     int max_enemies_defeated = 0;
    int dagger_power = initial_dagger_power;
    for (int strength : strengths) {
        // If dagger power is greater than or equal to the enemy's strength, defeat the enemy
        if (dagger_power >= strength) {
            max_enemies_defeated += 1;
            dagger_power += increase_rate;}
        // If dagger power is less than the enemy's strength, check if it's worth skipping the  enemy
        else if (strength - dagger_power <= dagger_power * decrease_rate) {
            dagger_power -= decrease_rate; }
        //if the enemy is skipping it's not worth the loop is terminated
        else {
            break;
        }
    }
return std::make_pair(max_enemies_defeated, dagger_power);
}

int main() {
    std::vector<int> strengths = {10, 20, 30, 15, 25, 40};
    int initial_dagger_power = 10;
    // the dagger defeat enemy the dagger power is incrase
    int increase_rate = 5;
    int decrease_rate = 2;
    std::pair<int, int> result = calculate_max_enemies(strengths, initial_dagger_power, increase_rate, decrease_rate);
    std::cout << "Enemies defeated: " << result.first << std::endl;
    std::cout << "Dagger power: " << result.second << std::endl;
    return 0;
}
