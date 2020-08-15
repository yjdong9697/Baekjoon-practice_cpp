#include <iostream>

using namespace std;

int main(void){
    int test_value;

    cin >> test_value;

    if (90 <= test_value){
        cout << "A\n";
    }
    
    else if (80 <= test_value){
        cout << "B\n";
    }
    
    else if (70 <= test_value){
        cout << "C\n";
    }

    else if (60 <= test_value){
        cout << "D\n";
    }

    else{
        cout << "F\n";
    }

    return 0;
}