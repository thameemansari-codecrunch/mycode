// C++ program to swap two
// numbers using 3rd variable
#include <iostream>
using namespace std;
int main()
{
int a = 12, b = 20;

cout<<"before swapp a=12 , b=20 ";


int value;

value = a;
a = b;
b = value;
cout<<"\n After swapping a = " << a << " , b = " << b<< endl;


return 0;
}
