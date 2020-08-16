#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int value[9];
    int max_value = 0;
    int max_index = 0;
    for(int i = 0; i < 9; i++){
        int value_data;
        cin >> value_data;
        if (value_data > max_value){
            max_value = value_data;
            max_index = i;
        }
    }

    cout << max_value << "\n";
    cout << max_index + 1 << "\n";

    return 0;

}