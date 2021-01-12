#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int app_num, delete_memory;
int memory[101];
int cost[101];

int dp[100][10001];

void dp_check(int index){
    if(index >= app_num) return;
    if(index == 0){
        dp[index][cost[index]] = memory[index];
    }
    else{
        dp[index][cost[index]] = max(dp[index][cost[index]], memory[index]);
        for(int i = 0; i < 10001; i++){
            if(dp[index - 1][i] != 0){
                dp[index][i + cost[index]] = max(dp[index][i + cost[index]], dp[index - 1][i] + memory[index]);
                dp[index][i] = max(dp[index][i], dp[index - 1][i]);
            }
        }
    }   
    dp_check(index + 1);
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> app_num >> delete_memory;

    for(int i = 0; i < app_num; i++){
        int temp;
        cin >> temp;
        memory[i] = temp;
    }

    for(int i = 0; i < app_num; i++){
        int temp;
        cin >> temp;
        cost[i] = temp;
    } // Data_store

    memset(dp, 0, sizeof(dp));

    dp_check(0);

    for(int i = 0; i < 10001; i++){
        if(dp[app_num - 1][i] >= delete_memory){
            cout << i << "\n";
            return 0;
        }
    }
}