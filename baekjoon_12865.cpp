#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define INF 123456789;

int item_num, max_weight;
int W[1000];
int V[1000];
int dp[1000][100001];

int dp_check(int index, int weight){
    if(weight < 0) return -INF; // BAD cases
    if(index < 0) return 0; // BAD cases
    if(dp[index][weight] != 0) return dp[index][weight]; // 이미 존재하는지 체크(Memoization)
    int current_weight = W[index];
    int current_value  = V[index];
    
    return dp[index][weight] = max(dp_check(index - 1, weight - current_weight) + current_value, dp_check(index - 1, weight));

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> item_num >> max_weight;

    for(int i = 0;i < item_num; i++){
        int weight, value;
        cin >> weight >> value;
        W[i] = weight;
        V[i] = value;
    }// Data store

    memset(dp, 0, sizeof(dp)); // Initialize 0

    dp_check(item_num - 1, max_weight);
    cout << dp[item_num -1][max_weight] << "\n";

    return 0;
}