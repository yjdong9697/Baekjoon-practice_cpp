#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main(void){
    string value1, value2;
    cin >> value1 >> value2;

    int value1_reverse = 0, value2_reverse = 0;

    for(int i = 0; i < 3; i++){
        int convert = value1[i] - '0';
        value1_reverse += convert * pow(10, i);
    } // reverse value1

    for(int i = 0; i < 3; i++){
        int convert = value2[i] - '0';
        value2_reverse += convert * pow(10, i);
    } // reverse value2

    // Compare

    if (value1_reverse >= value2_reverse){
        cout << value1_reverse << "\n";
    }
    
    else{
        cout << value2_reverse << "\n";
    }

    return 0;

}