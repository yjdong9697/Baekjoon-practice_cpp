#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
vector<int> data_store[200001];
int rumor_store[200001];
int spread_num[200001];
int N, M;

void bfs(int minute, vector<int> spread_store){
    vector<int> next_spread;

    for(int j = 0; j < spread_store.size(); j++){
        int spreader = spread_store[j];
        for(int i = 0; i < data_store[spreader].size(); i++){
            // 절반 넘는지 체크
            if((double)spread_num[data_store[spreader][i]] + 1 >= (double)data_store[data_store[spreader][i]].size() / 2){
                // 전파가 아얘 안된 상태
                if(rumor_store[data_store[spreader][i]] == -1){
                    rumor_store[data_store[spreader][i]] = minute + 1;
                    next_spread.push_back(data_store[spreader][i]);
                    spread_num[data_store[spreader][i]]++;
                }
                // 전파가 전에 되기는 했는데 더 빨리 전파가 될 수 있는 경우
                else continue;
            }
            else spread_num[data_store[spreader][i]]++;
        }
    }
    if(next_spread.empty()) return;
    bfs(minute + 1, next_spread);
    return;
}

int main(void){
    fastio;
    memset(rumor_store, -1, sizeof(rumor_store));
    memset(spread_num, 0, sizeof(spread_num));
    cin >> N;

    for(int i = 1; i <= N; i++){
        while(true){
            int temp;
            cin >> temp;
            if(temp == 0) break;
            data_store[i].push_back(temp);
        }    
    } // 저장정보 저장

    cin >> M;

    vector<int> spread;
    for(int i = 0; i < M; i++){
        int temp;
        cin >> temp;
        spread.push_back(temp);
        rumor_store[temp] = 0;
    }// 유포자 저장
    bfs(0, spread);

    for(int i = 1; i <= N; i++){
        cout << rumor_store[i] << " ";
    }
    cout << "\n";

    return 0;
}