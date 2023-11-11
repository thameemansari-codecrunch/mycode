
// C++ program to find out maximum profit by buying// and/ selling a share atmost k times given stock
// price of n days
//we installing climits header file
//Author:S.Thameem Ansari

#include <climits>
#include <iostream>
using namespace std;
 
// Function to find out maximum profit by buying &
// selling a share atmost t times given stock price
// of d days
//and we consider d as days t as trasaction
int maxProfit(int price[], int d, int t)
{
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using atmost
    // t transactions up to day i (including day i)
    //This line declares a 2D array called profit with dimensions 
    //(t + 1) x (d + 1) to store the maximum profit 
    int profit[t + 1][d + 1];
 
    // For day 0, you can't earn money
    // irrespective of how many times you trade
    //These loops initialize the profit array for cases where there are no transactions (t = 0) or no days (d = 0).
    for (int i = 0; i <= t; i++)
        profit[i][0] = 0;
       
    // profit is 0 if we don't do any transaction
    // (i.e. t =0)
    
    
    for (int j = 0; j <= d; j++)
        profit[0][j] = 0;
 //The loop iterates through transactions i from 1 to t and days j from 1 to d.
    // fill the table in bottom-up fashion
    for (int i = 1; i <= t; i++) {
        int prevDiff = INT_MIN;
        for (int j = 1; j < d; j++) {
            prevDiff = max(prevDiff,
                           profit[i - 1][j - 1] - price[j - 1]);
                           
                           
            profit[i][j] = max(profit[i][j - 1],
                               price[j] + prevDiff);
                              
                               cout << "\nPreviDff\n" << profit[i][j];
        }
    }
  cout << " \nMaximum profit is: "
     << profit[t][d - 1];
    return profit[t][d - 1];
}
 

int main()
{
    int transaction = 2;
    int price[9] = {100,180,260,310,40,535,695};
 
    int numOfElements = sizeof(price) / sizeof(price[0]);
    //calling maxProfit function
     maxProfit(price, numOfElements, transaction);
 
    return 0;
}
