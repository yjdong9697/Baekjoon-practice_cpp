#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

int main(void){
    string input_data;
    cin >> input_data; // input data

    int len_data = input_data.size();
    int result = 0;
    int count = 0;

    for(int i = 0; i < len_data; i++){
        
        // 레이저 후보지점

        if(input_data[i] == ')'){

            // 레이저 목록

            if(input_data[i - 1] == '('){
                count -= 1; // 막대기가 늘어난 것이 아니므로 -1
                result += count; // 자른 막대기 갯수
            }

            // 레이저가 아님(막대기의 끝) : 막대기 찌꺼기 1개 증가

            else{
                count -= 1; // 막대기가 끝났으므로 지움
                result += 1;
            }
        }

        // 일반적으로 ( 의 갯수는 막대기 갯수
        
        else{
            count += 1;
        }
    }

    cout << result << "\n";
    return 0;
}