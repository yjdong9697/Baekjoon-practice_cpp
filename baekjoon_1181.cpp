#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string , string);

int main(void){
    int n;
    cin >> n;

    string data_store[n];
    for (int i = 0; i < n; i++){
        cin >> data_store[i];
    } // data_store

    sort(data_store, data_store + n, compare);

    cout << data_store[0] << "\n";
    int check = 0; // initial setting

    for (int j = 1; j < n; j++){
        if (data_store[j] == data_store[check]){
            continue;
        }
        else{
            cout << data_store[j] << "\n";
            check = j;
        }   
    }
    return 0;
}

bool compare(string a, string b){
    if (a.size() == b.size()){
        return a < b;
    }
    else{
        return a.size() < b.size(); // 인자 두 개를 받는 비교 함수로, 첫 번째 인자가 더 작을 경우 true 를 리턴해야 합니다.        
    }   
}