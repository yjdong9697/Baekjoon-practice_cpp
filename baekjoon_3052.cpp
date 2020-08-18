#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int remain_data[10];
    for(int i = 0; i < 10; i++){
        int value;
        cin >> value;
        int remain_number = value % 42;
        remain_data[i] = remain_number;
    }
    sort(remain_data, remain_data + 10);
    
    int return_value = 1;

    for(int i = 1; i <10; i++){
        if (remain_data[i] != remain_data[i - 1]){
            return_value += 1;
        }
    }
    cout << return_value;
}