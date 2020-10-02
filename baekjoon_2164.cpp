#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(void){
    int n;
    cin >> n;
    queue<int> data_store;

    for(int i = 1; i < n + 1; i++){
        data_store.push(i);
    }// store data;

    while(n > 1){
        data_store.pop();
        int temp = data_store.front();
        data_store.pop();
        data_store.push(temp);
        n -= 1;
    }
    cout << data_store.front();

    return 0;

}