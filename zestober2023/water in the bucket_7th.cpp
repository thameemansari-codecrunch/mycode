//Author:S.Thameem Ansari// initialize the necessary file 
#include <iostream>

double drip_time(double T, double R, double C) {
    
    //initial time
    double time_to_fill = 0;
    
    // amount of water in the bucket
    double water_in_bucket = 0;
    while (water_in_bucket <= C) {
        water_in_bucket += 1 / T;
        time_to_fill += T;
        T *= R;
    }
    return time_to_fill;
}

int main() {
    double T = 1.0;
    double R = 0.9;
    double C = 5.0;
    double output = drip_time(T, R, C);
    std::cout << output << std::endl;
    return 0;
}
