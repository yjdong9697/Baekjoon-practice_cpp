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
    stack<int> stack_store;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        stack_store.push(temp);
    } // data_store

    int max = -1;
    int count = 0;

    for(int i = 0 ; i < n; i++){
        int compare = stack_store.top();
        if (compare > max){
            count += 1;
            max = compare;
        }
        stack_store.pop();
    }

    cout << count << "\n";
    return 0;
}