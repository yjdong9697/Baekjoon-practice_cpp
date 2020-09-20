#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> data_store;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    } // Data store

    stack<int> stack_store;
    int count = 2; // 1은 무조건 집어넣으므로 그 다음은 무조건 2 
    int index = 0; // 참조할 data_store의 index 저장
    stack_store.push(1); // 처음 1은 input으로 무조건 넣고 시작
    vector <string> result_store;
    result_store.push_back("+");

    while(index < n){
        
        // stack안에 있는 것보다 해당 index에 있는 값이 더 작으면 push한다.
        
        if ((stack_store.size() == 0) || (stack_store.top() < data_store[index])){
            stack_store.push(count);
            result_store.push_back("+");
            count += 1;
        }

        // 만약, 제일 위에 있는 것보다 더 작은 것을 index 값으로 가지는 경우 무조건 그 값을 pop시켜야하므로 절대로 안된다.
        
        else if(stack_store.top() > data_store[index]){
            cout << "NO\n";
            return 0;
        }

        // 같으면 pop시켜 빼낸다.

        else if(stack_store.top() == data_store[index]){
            index += 1;
            stack_store.pop();
            result_store.push_back("-");
        }

        // 먼역애 제일 위에 있는 것보다 더 큰 값을 index 값으로 가지는 경우 무조건 pop시켜서 제일 위에 있는 값을 내린다.
        else{
            stack_store.pop();
            result_store.push_back("-");
        }
    }

    for(int i = 0; i < result_store.size(); i++){
        cout << result_store[i] << "\n";
    }

    return 0;
}