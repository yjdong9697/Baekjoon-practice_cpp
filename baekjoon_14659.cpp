#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int bowl_num;
    cin >> bowl_num;

    vector<int> data_store;
    for(int i = 0; i < bowl_num; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }// Bowl data 저장

    int count_store = 0;
    int height_store = -1;
    int result = 0;

    for(int i = 0; i < bowl_num; i++){
        if(height_store < data_store[i]){
            height_store = data_store[i];
            result = max(count_store, result);
            count_store = 0;
        }
        else count_store += 1;
    }

    result = max(count_store, result);

    cout << result << "\n";
    return 0;
}