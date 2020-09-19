#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int main(void){
    stack <int> data_store;
    string input_data;
    cin >> input_data;

    int size_of_data = input_data.size();
    
    for(int i = 0; i < size_of_data; i++){
        if (input_data[i] == '('){
            data_store.push(-1);
        } 

        else if (input_data[i] == '['){
            data_store.push(-2);
        }

        else if (input_data[i] == ')'){
            int size_of_stack = data_store.size();
            int temp = 0;
            if (size_of_stack == 0){
                cout << "0\n"; // 적절하지 않은 스택
                return 0; // 종료
            }
            for(int i = 0; i < size_of_stack; i++){
                if (data_store.top() == -1){
                    data_store.pop(); // 제외하고 temp만 남겨둔다.
                    if (temp != 0){
                        data_store.push(2 * temp);
                    }
                    else{
                        data_store.push(2);
                    }
                    break;
                }
                else if (data_store.top() == -2){
                    cout << "0\n"; // 적절하지 않은 스택
                    return 0; // 종료
                }
                else{
                    temp += data_store.top();
                    data_store.pop();
                }
            }
        }

        else if (input_data[i] == ']'){
            int size_of_stack = data_store.size();
            int temp = 0;
            if (size_of_stack == 0){
                cout << "0\n"; // 적절하지 않은 스택
                return 0; // 종료
            }
            for(int i = 0; i < size_of_stack; i++){
                if (data_store.top() == -2){
                    data_store.pop(); // 제외하고 temp만 남겨둔다.
                    if (temp != 0){
                        data_store.push(3 * temp);
                    }
                    else{
                        data_store.push(3);
                    }
                    break;
                }
                else if (data_store.top() == -1){
                    cout << "0\n"; // 적절하지 않은 스택
                    return 0; // 종료
                }
                else{
                    temp += data_store.top();
                    data_store.pop();
                }
            }
        }
    }
    int final_stack_size = data_store.size();
    int final_temp_store = 0;
    for(int i = 0; i < final_stack_size; i++){
        if (data_store.top() == -1 || data_store.top() == -2){
            cout << "0\n";
            return 0; // 적절하지 않은 스택
        }
        else{
            final_temp_store += data_store.top();
            data_store.pop(); // 계속해서 숫자들을 더해나간다. 단, -1이나 -2가 나오면 종료
        }
    }

    cout << final_temp_store << "\n";
    return 0;
}