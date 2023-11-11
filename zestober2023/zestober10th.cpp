#include <stdio.h>#define MAX_r 10
#define MAX_c 10
 //Find the maximum time to reach the map with limitation
 //so we using 2d array and 3d array for map and maxvalfortune 
 //And entering two  variable r and c we consider r as row and c as column
 //And we using nested for loop concept to convert the programe clearly
 // Author:S.Thameem Ansari
int maxVal(int a, int b) {
    return (a > b) ? a : b;
}
 
int findMaxFortuneScore(int map[MAX_r][MAX_c], int r, int c, int maxLocations) {
    int threeDtable[MAX_r][MAX_c][MAX_r * MAX_c + 1];
 
    //Entering threeDtable array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k <= maxLocations; k++) {
                threeDtable[i][j][k] = 0;
            }
        }
    }
 
    // Entering the first cell
    threeDtable[0][0][1] = map[0][0];
  
    //complete the threeDtable array
    for (int k = 2; k <= maxLocations; k++) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int maxScore = 0;
 
                // Try to going sides left, right, up, and down
                if (i > 0) {
                   
                    
                    maxScore = maxVal(maxScore, threeDtable[i - 1][j][k - 1]);
                }
                if (i < r - 1) {
                    maxScore = maxVal(maxScore, threeDtable[i + 1][j][k - 1]);
                }
                if (j > 0) {
                    maxScore = maxVal(maxScore, threeDtable[i][j - 1][k - 1]);
                }
                if (j < c - 1) {
                    maxScore = maxVal(maxScore, threeDtable[i][j + 1][k - 1]);
                }
 
                threeDtable[i][j][k] = maxScore + map[i][j];
                printf("threeDtable %d\n",threeDtable[i][j][k]);
            }
        }
    }
 
    // We Find the maximum fortune score
    int maxFortune = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            maxFortune = maxVal(maxFortune, threeDtable[i][j][maxLocations]);
        }
    }
 
    return maxFortune;
}
 
int main() {
    int map[MAX_r][MAX_c] = {{9,5, 2}, {2, 7, 1}, {6, 2, 7}};
    
    int r = 3;
    int c = 3;
    int maxLocations = 5;
    int result = findMaxFortuneScore(map, r, c, maxLocations);
    printf("Maximum value Fortune Score: %d\n", result);
 
    return 0;
}
