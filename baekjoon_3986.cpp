#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int count = 0;

    for(int i = 0; i < n; i++){
        bool check_good_word = true;
        string test_case;
        cin >> test_case;

        int len_data = test_case.size();
        stack <char> check_good;

        for(int j = 0; j < len_data; j++){
            if (test_case[j] == 'A'){
                if(check_good.empty()){
                    check_good.push(test_case[j]);
                }
                else if(check_good.top() != 'A'){
                    check_good.push(test_case[j]);
                }

                else{
                    check_good.pop();
                }

            }
            else if (test_case[j] == 'B'){
                if(check_good.empty()){
                    check_good.push(test_case[j]);
                }
                else if(check_good.top() != 'B'){
                    check_good.push(test_case[j]);
                }

                else{
                    check_good.pop();
                }

            }
        }
        if (check_good.empty()){
            count += 1;
        }
    }

    cout << count << "\n";
    return 0;

}