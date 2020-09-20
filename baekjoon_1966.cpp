#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

int main(void){
    int num;
    cin >> num;
    
    for(int i = 0; i < num; i++){
        int n, m;
        cin >> n >> m;
        int count = 1;
        queue<pair<int,int> > data_store;
        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            pair<int, int> temp_store;
            temp_store.first = temp;
            if (j == m){
                temp_store.second = 1; // 문제에서 요구한 m번째를 따로 체크
            }
            else{
                temp_store.second = 0; // Default case setting
            }
            
            data_store.push(temp_store);
        } // store data

        // 문제에서 요구한 케이스가 나올때까지 계속해서 맨 앞을 수정

        while(data_store.size() -1 != 0){
            queue<pair<int,int> > temp = data_store;
            int front = temp.front().first;
            bool check = true;
            
            // Front에 놓인 숫자가 max값인지 확인하는 작업
            for(int j= 0; j < data_store.size() - 1; j++){
                temp.pop();
                if(front < temp.front().first){
                    check = false;
                    break;
                }
            }

            // 맨 앞에 놓인 숫자가 max인 경우

            if (check == true){
                if(data_store.front().second == 1){
                    break; // 맨 앞에 놓인 숫자가 내가 고르고자 하는 수인 경우
                }
                else{
                    data_store.pop();
                    count += 1; // 아닌 경우 >> 나머지 숫자들을 가지고 다시 반복
                }
            }

            // 맨 앞에 놓인 숫자가 max가 아닌 경우

            else{
                pair <int, int> temp_num = data_store.front();
                data_store.pop();
                data_store.push(temp_num); // 맨 앞에 놓인 숫자를 뒤로 배치시킨다.
            }
        }
        cout << count << "\n"; // 문제에서 요구하는 값 출력
    }

    return 0;
}