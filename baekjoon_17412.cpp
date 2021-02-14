#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321;

const int MAX_N = 401;

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
                if(adj[here][i] -> residual() > 0 && parent[adj[here][i] -> to] == nullptr){
                    q.push(there);
                    parent[there] = adj[here][i];
                }
            }
        }
        if(parent[sink] == nullptr) break;
        int amount = INF;

        // 간선 위 모든 지점에서 최소 capacity만큼을 flow를 흘려줌
        for(int p = sink; p != source; p = parent[p] -> from){
            parent[p] -> add_flow(1);
        }
        max_flow++;
    }
    return max_flow;
}

int main(void){
    fastio;
    int N, K; // Test case num
    cin >> N >> K;

    for(int i = 0; i < K; i++){
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1);
    }
    cout << networkFlow(1, 2) << "\n";
    return 0;
}