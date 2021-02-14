#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321;

using namespace std;

int capacity[2003][2003] = {0}; 
int flow[2003][2003] = {0};
int N, M, K;

int networkFlow(){
    int totalFlow = 0;
    while(true){
        vector<int> parent(N + M + 3, -1);
        queue<int> q;
        parent[0] = 0;
        q.push(0);
        while(!q.empty() && parent[N + M + 1] == - 1){
            int here = q.front(); q.pop();
            for(int there = 0; there <= N + M + 2; there++){
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1){
                    q.push(there);
                    parent[there] = here;
                }
            }
        }

        if(parent[N + M + 1] == - 1) break; // 만족하는 루트가 없는 경우
        int amount = INF;

        for(int p = N + M + 1; p != 0; p = parent[p]){
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }
        for(int p = N + M + 1; p != 0; p = parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalFlow += amount;
    }
    return totalFlow;
}

int main(void){
    fastio;
    cin >> N >> M >> K;

    // 직원과 source 사이의 capacity를 1로 조정(1~N번째 index) + 2002번째 index에 K만큼의 가중치를 줌
    for(int i = 1; i <= N; i++){
        capacity[0][i] = 1;
        capacity[N + M + 2][i] = 1;
    }
    capacity[0][N + M + 2] = K;

    // 일과 sink 사이의 capacity를 1로 조정(N+1~N+M번째 index)
    for(int i = N + 1; i <= N + M; i++){
        capacity[i][N + M + 1] = 1;
    }

    // 사람과 일을 연결지음
    for(int i = 1; i <= N; i++){
        int work_num;
        cin >> work_num;
        for(int j = 0; j < work_num; j++){
            int temp;
            cin >> temp;
            capacity[i][temp + N] = 1;
        }
    }

    cout << networkFlow() << "\n";
    return 0;
}