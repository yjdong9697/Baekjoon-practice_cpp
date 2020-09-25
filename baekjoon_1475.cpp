#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    int check_value[10] = {0};
    vector<int> data_store;
    int temp = n;

    if (temp == 0){
        cout << 1 << "\n";
        return 0;
    }

    while(temp != 0){
        int remain_temp = temp % 10;
        temp /= 10;
        data_store.push_back(remain_temp);
    }

    int vector_size = data_store.size();

    for(int i = 0; i < vector_size; i++){
        check_value[data_store[i]] += 1;
    }

    int changeable_num = (check_value[6] + check_value[9]) / 2 + (check_value[6] + check_value[9]) % 2;
    
    check_value[6] = 0;
    check_value[9] = 0;

    int result_cal = *max_element(check_value, check_value + 10); // max element count except 6 and 9

    if (result_cal > changeable_num){
        cout << result_cal << "\n";
        return 0;
    }
    else{
        cout << changeable_num << "\n";
        return 0;
    }
}