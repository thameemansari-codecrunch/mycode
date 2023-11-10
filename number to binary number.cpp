#include <iostream>  
using namespace std;  
int main()

{
   
int a[10], n, i;

cout<<"Enter the number to convert: ";  

cin>>n;    

for(i=0; n>0; i++)

{    
a[i]=n%2;    
n= n/2;

}    
cout<<"Binary of the given number= ";    
  for(i=i-1 ;i>=0 ;i--)
 
 
  //a[i] = n % 2;: Calculates the remainder of n when divided by 2 and stores it in the i-th position of the array a. This effectively calculates the binary digit.
 
//n = n / 2;: Updates the value of n by integer division, removing the last digit of n.

{    
cout<<a[i];    

}    
}  
