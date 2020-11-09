#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // 입력 받을 숫자 갯수
    int n;
    cin >> n;

    vector<int> data_store;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }// 데이터 저장

    //증감증 or 감증감

    //증감증 체크
    int first_check = 0;
    while(first_check + 1 < n){
        if(data_store[first_check] <= data_store[first_check + 1]){
            first_check += 1;
        }
        else{
            break;
        }
    }
    // 그 자체가 증가함수인 경우
    if(first_check == n - 1){
        cout << "0\n";
        return 0;
    }

    int second_check = first_check + 1;
    while(second_check + 1 < n){
        if(data_store[second_check] <= data_store[second_check + 1]){
            second_check += 1;
        }
        else{
            break;
        }
    }

    if(data_store[0] < data_store[n - 1]){
        second_check = -1;
    }

    //감증감 체크
    int first_check_2 = 0;
    while(first_check_2 + 1 < n){
        if(data_store[first_check_2] >= data_store[first_check_2 + 1]){
            first_check_2 += 1;
        }
        else{
            break;
        }
    }
    // 그 자체가 감소함수인 경우
    if(first_check_2 == n - 1){
        cout << "0\n";
        return 0;
    }

    int second_check_2 = first_check_2 + 1;
    while(second_check_2 + 1 < n){
        if(data_store[second_check_2] >= data_store[second_check_2 + 1]){
            second_check_2 += 1;
        }
        else{
            break;
        }
    }
    if(data_store[0] > data_store[n - 1]){
        second_check_2 = -1;
    }

    if(second_check == n - 1){
        if(second_check_2 == n - 1){
            cout << min(first_check + 1, first_check_2 + 1) << "\n";
            return 0;
        }
        else{
            cout << first_check + 1 << "\n";
            return 0;
        }        
    }
    else{
        if(second_check_2 == n - 1){
            cout << first_check_2 + 1 << "\n";
            return 0;
        }
        else{
            cout << -1 << "\n";
            return 0;
        } 
    }
}