#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int team_num;
    cin >> team_num;
    vector<int> data_store;

    for(int i = 0; i < team_num * 2; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }// Data_store

    sort(data_store.begin(), data_store.end()); // Sorting data

    int min_value = 123456789;
    for(int i = 0; i < team_num; i++){
        min_value = min(min_value, data_store[i] + data_store[2 * team_num - 1 - i]);
    }

    cout << min_value << "\n";
    return 0;
}