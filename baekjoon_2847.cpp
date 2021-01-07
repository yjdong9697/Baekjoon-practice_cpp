#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;

    vector<int> data_store;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }

    int check_value = data_store[N - 1];
    int result = 0;

    for(int i = N - 2; i >= 0; i--){
        if(data_store[i] < check_value) check_value = data_store[i];
        else{
            result += data_store[i] - (check_value - 1);
            check_value = check_value - 1;
        }
    }

    cout << result << "\n";
    return 0;
}