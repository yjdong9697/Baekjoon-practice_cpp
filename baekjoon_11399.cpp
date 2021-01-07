#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    cin >> num;
    
    vector<int> data_store;
    int sum = 0;
    for(int i = 0; i < num; i++){
        int temp;
        cin >> temp;
        sum += temp;
        data_store.push_back(temp);
    }

    sort(data_store.begin(), data_store.end());

    int result = sum;

    while(data_store.size()){
        result += sum - data_store.back();
        sum -= data_store.back();
        data_store.pop_back();
    }

    cout << result << "\n";
    return 0;
}