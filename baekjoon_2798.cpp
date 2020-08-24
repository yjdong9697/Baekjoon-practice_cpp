#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main(void){
    int num, purpose;
    cin >> num >> purpose;

    // Store input

    int value[num];
    for(int i = 0; i < num; i++){
        int input_value;
        cin >> input_value;
        value[i] = input_value;
    }

    // Brute force

    int dif_store = 1000000;
    int sum_store = 0;

    for(int a = 0; a < num - 2; a++){
        for(int b = a + 1; b < num - 1; b++){
            for (int c = b + 1; c < num; c++){
                int cal_data = value[a] + value[b] + value[c];
                int diff_value = purpose - cal_data;
                if (dif_store > diff_value){
                    if (diff_value >= 0){
                        dif_store = diff_value;
                        sum_store = cal_data;
                    }
                    
                }
            }
        }
    }
    
    cout << sum_store << "\n";

    return 0;
}