//si=amount*rate*time
#include<iostream>
using namespace std;
int main()
{
 int amount,rate,time,si;
    printf("\n enter the amount:");
    scanf("%d",&amount);
    printf("\n enter the rate:");
    scanf("%d",&rate);
    printf("\n enter the time:");
    scanf("%d",&time);
    si=amount*rate*time/100;
    printf("%d",&si);
   
    return 0;
   
   
   
}
