#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cake_num, cut_num;
    cin >> cake_num >> cut_num;

    vector<int> ten_multiplied_store;
    vector<int> not_ten_multiplied_store;
    int count = 0;
    int check_value = 0;
    for(int i = 0; i < cake_num; i++){
        int temp;
        cin >> temp;
        if(temp % 10 == 0){
            if(temp == 10) count += 1; // 자르지 않아도 됨
            else{
                ten_multiplied_store.push_back(temp);
            }
        }
        else{
            check_value += temp / 10;
            not_ten_multiplied_store.push_back(temp);
        }
    }

    sort(ten_multiplied_store.begin(), ten_multiplied_store.end());
    sort(not_ten_multiplied_store.begin(), not_ten_multiplied_store.end());

    for(int i = 0; i < ten_multiplied_store.size(); i++){
        if(cut_num == 0) break;
        else{
            if(ten_multiplied_store[i] / 10 - 1 <= cut_num){
                count += ten_multiplied_store[i] / 10;
                cut_num -= ten_multiplied_store[i] / 10 - 1;
            }
            else{
                count += cut_num;
                cut_num = 0;
                break;
            }
        }
    }

    if(cut_num > 0 && check_value > 0){
        for(int i = 0; i < not_ten_multiplied_store.size(); i++){
            if(cut_num == 0) break;
            if(cut_num >= not_ten_multiplied_store[i] / 10){
                count += not_ten_multiplied_store[i] / 10;
                cut_num -= not_ten_multiplied_store[i] / 10;
            }
            else{
                count += cut_num;
                break;
            }
        }
    }

    cout << count << "\n";
    return 0;

}