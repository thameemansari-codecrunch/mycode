#include <iostream>
int main() {
    using namespace std;
   char letter;
   
   
    cout << "Enter a letter";
     cin >> letter;
     
   
   
    switch ( letter ) {
        case 'a' :
            cout << " a  is a vowels";
            break;
        case 'e':
           cout << " e is a vowels ";
            break;
        case 'i' :
            cout << " i is a vowels ";
            break;
        case 'o' :
            cout << " o is a vowels ";
            break;
            case 'u' :
            cout<<" uis a vowels  ";
            break;
        default:
            cout<<"it is not a vowels";
            break;
    }

    return 0;
} 
