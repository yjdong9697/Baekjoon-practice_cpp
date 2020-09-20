#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

int main(void){
    int k;
    cin >> k;

    stack<int> data_store;
    for(int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        if (temp == 0){
            data_store.pop();
        }
        else{
            data_store.push(temp);
        }
    }

    int result = 0;
    int len_data = data_store.size();

    for(int i = 0; i < len_data; i++){
        result += data_store.top();
        data_store.pop();
    }

    cout << result << "\n";
    return 0;
}