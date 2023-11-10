#include <iostream>
using namespace std;

int main() {

  int number;

  cout << "Enter an integer: ";
  cin >> number;

  // checks if the number is below 100;
  if (number >100 ) {
    cout << "yes it is below 100: " << number ;
  }
    else if(number >50){
    cout <<"yes it is greater 50: " << number ;
    }
    else if(number >10){
        cout << "yes it is greater 10: " << number ;
       
       
    }
     return 0;
}
