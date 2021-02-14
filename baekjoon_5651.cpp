#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321;

const int MAX_N = 301;

using namespace std;
typedef pair<int, int> pii;

struct edge{
    int from, to, flow, capacity;
    edge* reverse_edge;
    edge(int u, int v, int c) : from(u), to(v), capacity(c), flow(0)
    {}
    int residual(){
        return capacity - flow;
    }
    void add_flow(int amount){
        flow += amount;
        reverse_edge -> flow -= amount;
    }
};

vector<edge*> adj[MAX_N];

void add_edge(int u, int v, int c, bool dir = true){
    edge* e1 = new edge(u, v, c);
    edge* e2 = new edge(v, u, dir ? 0 : c);
    e1 -> reverse_edge = e2;
    e2 -> reverse_edge = e1;
    adj[u].push_back(e1);
    adj[v].push_back(e2);
    return;
}

void networkFlow(int source, int sink){
    while(true){
        vector<edge*> parent(MAX_N, nullptr);
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == nullptr){
            int here = q.front(); q.pop();
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i] -> to;
                if(adj[here][i] -> residual() > 0 && parent[adj[here][i] -> to] == nullptr){
                    q.push(there);
                    parent[there] = adj[here][i];
                }
            }
        }
        if(parent[sink] == nullptr) break;
        int amount = INF;

        // 간선 상에서 최소 capacity를 Find
        for(int p = sink; p != source; p = parent[p] -> from){
            amount = min(amount, parent[p] -> residual());
        }
        // 간선 위 모든 지점에서 최소 capacity만큼을 flow를 흘려줌
        for(int p = sink; p != source; p = parent[p] -> from){
            parent[p] -> add_flow(amount);
        }
    }
    return;
}

bool solve(int source, int sink){
    vector<edge*> parent(MAX_N, nullptr);
    queue<int> q;
    q.push(source);
    while(!q.empty() && parent[sink] == nullptr){
        int here = q.front(); q.pop();
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i] -> to;
            if(adj[here][i] -> residual() > 0 && parent[adj[here][i] -> to] == nullptr){
                q.push(there);
                parent[there] = adj[here][i];
            }
        }
    }
    if(parent[sink] == nullptr) return false;
    return true;
}

int main(void){
    fastio;
    int K; // Test case num
    cin >> K;

    for(int i = 0; i < K; i++){
        int N, M;
        cin >> N >> M;

        int input_store[301][301] = {0};
        int input_num_store[301][301] = {0};
        for(int j = 0; j < M; j++){
            int u, v, c;
            cin >> u >> v >> c;
            input_store[u][v] += c;
            input_num_store[u][v] += 1;
        }

        for(int i = 0; i < 301; i++){
            for(int j = 0; j < 301; j++){
                if(input_store[i][j] > 0) add_edge(i, j, input_store[i][j]);
            }
        }

        networkFlow(1, N);
        int print_value = 0;
        for(int i = 0; i < MAX_N; i++){
            for(int j = 0; j < adj[i].size(); j++){
                if(adj[i][j] -> residual() == 0 && adj[i][j] -> capacity > 0){
                    if(!solve(i, adj[i][j] -> to)) print_value += input_num_store[i][adj[i][j] -> to];                    
                }
            }
        }

        cout << print_value << "\n";

        // 인접리스트 초기화
        for(int j = 0; j < MAX_N; j++){
            adj[j].clear();
        }
    }
    return 0;
}