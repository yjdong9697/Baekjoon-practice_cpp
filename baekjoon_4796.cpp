#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int max_value, check_num, holiday_num;
    int result;
    for(int i = 1; ;i++){
        cin >> max_value >> check_num >> holiday_num;
        if(max_value == 0 && check_num == 0 && holiday_num == 0){
            return 0; // program terminated
        }
        if(holiday_num >= max_value){
            if((holiday_num - max_value) % check_num >= check_num - max_value){
                result = max_value + (holiday_num - max_value) / check_num * max_value + (holiday_num - max_value) % check_num - (check_num - max_value);
            }
            else{
                result = max_value + (holiday_num - max_value) / check_num * max_value;
            }
            
            cout << "Case " << i << ": " << result << "\n";
        }       
    }

    return 0;
}