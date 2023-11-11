
//Author::S.Thameem Ansari
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>

int lcm(int a, int b) {
    return std::abs(a * b) / std::gcd(a, b);
}

int calculate_alignment_time(std::vector<int> speeds, std::vector<int> radii) {
    std::vector<double> circumferences;
    for (int radius : radii) {
        double circumference = 2 * M_PI * radius;
        circumferences.push_back(circumference);
    }

    std::vector<double> times;
    for (int i = 0; i < speeds.size(); i++) {
        double time = circumferences[i] / speeds[i];
        times.push_back(time);
    }

    int alignment_time = std::reduce(times.begin(), times.end(), 1, lcm);
    return alignment_time;
}

int main() {
    std::vector<int> speeds = {10, 15, 20};
    std::vector<int> radii = {100, 150, 200};
    int alignment_time = calculate_alignment_time(speeds, radii);
    std::cout << "Alignment Time: " << alignment_time << " hours" << std::endl;
    return 0;
}
