#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> road[10001];
int visited[10001];
int citizen_num[10001];
int dp[10001][2]; // i번쨰 인덱스가 선택되었을 떄 : 1, 선택되지 않았을 때 0
                  // 해당 i번째를 기준으로 시민들 수와 합의 최댓값

int civil_num;

void dfs(int node){
    if(visited[node] != 0) return;
    else{
        visited[node] = 1; // 방문 처리
        int zero_check = 0;
        int one_check = 0;
        for(int i = 0; i < road[node].size(); i++){
            if(visited[road[node][i]] == 0){
                dfs(road[node][i]);
                one_check += dp[road[node][i]][0];
                zero_check += max(dp[road[node][i]][0], dp[road[node][i]][1]);
            }
        }
        dp[node][0] = zero_check;
        dp[node][1] = one_check + citizen_num[node];
        return;
    }
}

int main(void){
    cin >> civil_num;
    
    for(int i = 1; i <= civil_num; i++){
        int temp;
        cin >> temp;
        citizen_num[i] = temp;
    }// Citizen store

    memset(road, 0, sizeof(road)); // Initializa road memory to 0

    for(int i = 1; i <= civil_num - 1; i++){
        int civil1, civil2;
        cin >> civil1 >> civil2;
        road[civil1].push_back(civil2);
        road[civil2].push_back(civil1);
    }

    memset(dp, 0, sizeof(dp));

    // 위에가 선택되면 >> 아래는 선택이 안됨(DFS로 처리하면됨 아래서부터)
    // 미선택을 0, 선택을 1로 취급하자.
    dfs(1);

    cout <<max(dp[1][0], dp[1][1]) << "\n"; // 최댓값 출력
    return 0;
}