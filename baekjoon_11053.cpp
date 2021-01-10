#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N;
    cin >> N;

    vector<int> data_store;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }

    int dp[1000] = {0};

    for(int i = 0; i < N; i++){
        int max_store = -1;
        int max_index = -1;
        for(int j = 0; j < i; j++){
            // 큰 경우
            if(data_store[i] > data_store[j]){
                if(max_store < dp[j]){
                    max_index = j;
                    max_store = dp[j];
                }
            }
        }

        // 앞에 작은 것이 없는 경우
        if(max_store == -1){
            dp[i] = 1;
        }
        else{
            dp[i] = dp[max_index] + 1;
        }
    }

    int result = -1;
    for(int i = 0; i < N; i++){
        result = max(result, dp[i]);
    }

    cout << result << "\n";
    return 0;
}