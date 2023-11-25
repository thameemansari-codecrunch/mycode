#include <iostream>
int main() {
    using namespace std;
    int ages,type;
   
   
    cout << "Enter a age";
     cin >> ages;
     
    type=ages/10;
   
    switch (type) {
        case 10:
            cout << " you are a old ";
            break;
        case 9:
           cout << " you are a old   ";
            break;
        case 8:
            cout << " you are a old ";
            break;
        case 7:
            cout << " you are a old  ";
            break;
            case 6:
            cout << " you are a adult ";
            break;
            case 5:
            cout << "you are a adult ";
            break;
            case 4:
            cout << "you are a adult ";
             case 3:
            cout << " you are a adult ";
            break;
            case 2:
            cout << " you are a major ";
            break;
            case 1:
            cout << " you are a kid ";
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << " can't find your age ";
            break;
    }

    return 0;
} 
