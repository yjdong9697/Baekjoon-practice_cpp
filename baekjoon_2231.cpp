#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int input_value;
    cin >> input_value;
    for(int i = 1; i <= input_value; i++){
        int sum = i;
        int temp = i;
        while(temp){
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == input_value){
            cout << i << "\n";
            return 0;
        }
        
    }

    cout << 0 << "\n";
    return 0;

}