#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

int city_num, passenger_num;
vector<int> child_num_store[51];
int road[51][51];
// 단, k = 0일때는 1로 초기화 할 것(곱 계산 할 때 필요함)
int dp[51][51][51]; // i : i를 루트로 가지는, j : 자식 중 j번째 자식까지 고려, k : 총 노드의 갯수 (만족하는 경우의 수)
int visited[51];
ll result = 0;

void refresh(){
    result = result % 1000000007;
    return;
}

int refresh(int value){
    return value % 1000000007;
}

void dfs(int index){
    if(visited[index] == 1) return; // Already visit (Early exit)
    visited[index] = 1; // 방문처리

    for(int i = 1; i < child_num_store[index].size();){
        if(visited[child_num_store[index][i]] == 1){
            child_num_store[index].erase(child_num_store[index].begin() + i); // 이미 방문한 경우 지워버림
        }
        else{
            dfs(child_num_store[index][i]);
            i++;
        }
    } // 자식들 업데이트

    for(int i = 1; i < child_num_store[index].size(); i++){
        if(i == 1){
            for(int j = 0; j <= passenger_num; j++){
                if(j == 0) dp[index][i][j] = 1; // Base case 설정
                else{
                    dp[index][i][j] += refresh(dp[child_num_store[index][i]][child_num_store[child_num_store[index][i]].size() - 1][j - 1]);
                }
            }
        }
        else{
            for(int j = 0; j <= passenger_num; j++){
                if(j == 0) dp[index][i][j] = 1; // Base case 설정
                else{
                    for(int k = 0; k < j; k++){
                        dp[index][i][j] += refresh(dp[index][i - 1][j - k] * dp[child_num_store[index][i]][child_num_store[child_num_store[index][i]].size() - 1][k]);
                    }
                }
            }
        }
    }
    dp[index][0][1] = 1;
    dp[index][0][0] = 1;
    return;
      
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> city_num >> passenger_num;

    // 초기화
    memset(road, 0, sizeof(road));
    memset(dp, 0, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    memset(road, 0, sizeof(road));

    for(int i = 0; i < city_num - 1; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        road[temp1][temp2] = 1;
        road[temp2][temp1] = 1;
    }

    for(int i = 1; i <= city_num; i++){
        child_num_store[i].push_back(0); // Trash data (index 맞추는 용도)
        for(int j = 1; j <= city_num; j++){
            if(road[i][j] == 1){
                child_num_store[i].push_back(j);
            }
        }
    } // 자식 미리 저장해놓음
    dfs(1);

    for(int i = 1; i <= city_num; i++){
        result += dp[i][child_num_store[i].size() - 1][passenger_num];
        refresh();     
    }

    cout << result << "\n";
    return 0;
}