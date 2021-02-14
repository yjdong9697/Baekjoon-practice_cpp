#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

const int MAX_N = 402;

struct edge{
    int from, to, capacity, flow;
    edge* reverse_edge;
    edge(int u, int v, int c) : from(u), to(v), capacity(c), flow(0)
    {}
    int residual(){
        return capacity - flow;
    }
    void add_flow(int amount){
        flow += amount;
        reverse_edge -> flow -= amount;
        return;
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
}

int networkFlow(int source, int sink){
    int max_flow = 0;
    while(true){
        vector<edge*> parent(MAX_N, nullptr);
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == nullptr){
            int here = q.front(); q.pop();
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i] -> to;
                if(adj[here][i] -> residual() > 0 && parent[there] == nullptr){
                    q.push(there);
                    parent[there] = adj[here][i];
                }
            }
        }
        if(parent[sink] == nullptr) break;
        // 어차피 residual이 1일수밖에 없으므로 min residual 구하는 것은 생략
        for(int i = sink; i != source; i = parent[i] -> from){
            parent[i] -> add_flow(1);
        }
        max_flow++;
    }
    return max_flow;
}

int main(void){
    fastio;
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        int num;
        add_edge(0, i, 1);
        cin >> num;
        for(int j = 0; j < num; j++){
            int value;
            cin >> value;
            add_edge(i, value + N, 1);
        }
    }
    for(int i = 1; i <= M; i++){
        add_edge(N + i, N + M + 1, 1);
    }
    cout << networkFlow(0, N + M + 1) << "\n";
    return 0;
}