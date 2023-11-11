#include<iostream>
using namespace std;
main( )
{  
int arr[4][3] = {
{ 1, 2, 3 },
{4, 5, 6},
{ 7, 8, 9 },
{ 10, 11, 12 }
} ;

int i,j;

cout<<"Printing a 2D Array:\n";
for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{
cout<<"\t"<<arr[i][j];
}
cout<<endl;
}
}
