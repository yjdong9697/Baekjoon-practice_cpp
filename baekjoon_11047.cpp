#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> coin_type_store;
int N, K;

int find_index(){
    for(int i = 0; i < N; i++){
        if(coin_type_store[i] > K){
            return i - 1;
        }
    }
    return N - 1; // 전부 다 K보다는 작은 상황
}

int main(void){
    
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        coin_type_store.push_back(temp);
    }

    sort(coin_type_store.begin(), coin_type_store.end());
    int index_store = 0;
    int result = 0;

    while(K != 0){
        int index = find_index();
        result += K / coin_type_store[index];
        K -= coin_type_store[index] * (K / coin_type_store[index]);
    }

    cout << result << "\n";
    return 0;
}