
//Author:S.Thameem Ansari//initializing  necessary file
#include <iostream>
using namespace std;

int bounces() {
    int totalbounces = 0;
        float startingH, bouncepercent, threshold;
        cout << "Enter the starting height: ";
        cin >> startingH;
        cout << "Enter the bounce percentage: ";
        cin >> bouncepercent;
        cout << "Enter the threshold height: ";
        cin >> threshold;
        if (startingH <= threshold) {
            return totalbounces;
        }
        if (bouncepercent >= 1) {
            cout << "bounce percent should be between 0 and less than 1" << endl;
            return 0; 
        }
        float v = 0;
        float bounces = 0;
        float r = startingH;
        while (r > threshold) {
            r = r * bouncepercent;
            v = v + 1;
        }
        bounces = (startingH * bouncepercent) * (v - 1);
        totalbounces += bounces;
        cout << "Bounces: " << int(bounces) << endl;
        cout << "total bounces so far: " << int(totalbounces) << endl;
       
    return 0;
}

int main() {
    bounces();
    return 0;
}
