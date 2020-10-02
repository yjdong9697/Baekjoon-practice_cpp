#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        stack <char> stack_data;
        int temp_size = temp.size();
        bool final_check = true;
        for(int j = 0; j < temp_size; j++){
            if(temp[j] == '('){
                stack_data.push('(');
            }
            else{
                if(stack_data.empty() != 1){
                    if(stack_data.top() == '('){
                        stack_data.pop();
                    }
                    else{
                        cout << "NO\n";
                        final_check = false;
                        break;
                    }    
                }
                else{
                    cout << "NO\n";
                    final_check = false;
                    break;
                }           
            }
        }
        if(stack_data.empty() == 1){
            if(final_check == true){
                cout << "YES\n";
            }
        }
        else{
            cout << "NO\n";
        }
        
    }

    return 0;

}