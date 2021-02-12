#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321;

using namespace std;
typedef long long ll;

int ARR_NUM;
int capacity[52][52]; int flow[52][52];

int networkFlow(int source, int sink){
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while(true){
        vector<int> parent(52, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1){
            int here = q.front(); q.pop();
            for(int there = 0; there < 52; there++){
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1){
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1) break; // 더이상 증가하는 경로가 없는 경우

        int amount = INF;
        for(int p = sink; p != source; p = parent[p]){
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for(int p = sink; p != source; p = parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        
        totalFlow += amount;
    }
    return totalFlow;
}

int change_index(char x){
    if('a' <= x && x <= 'z'){
        return x - 'a' + 26;
    }
    return x - 'A';
}

int main(void){
    fastio;
    memset(capacity, 0, sizeof(capacity));
    cin >> ARR_NUM;

    for(int i = 0; i < ARR_NUM; i++){
        char start, end;
        int capacity_temp;
        cin >> start >> end >> capacity_temp;
        int start_index = change_index(start);
        int end_index = change_index(end);
        capacity[start_index][end_index] += capacity_temp;
        capacity[end_index][start_index] += capacity_temp;
    }

    cout << networkFlow(0, 25) << "\n";

    return 0;
}