#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321;

const int MAX_N = 501;

using namespace std;

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
                    parent[there] = adj[here][i];
                    q.push(there);
                }
            }
        }
        if(parent[sink] == nullptr) break;
        int amount = INF;
        for(int p = sink; p != source; p = parent[p] -> from){
            amount = min(amount, parent[p] -> residual());
        }

        for(int p = sink; p != source; p = parent[p] -> from){
            parent[p] -> add_flow(amount);
        }
        max_flow += amount;
    }
    return max_flow;
}

int main(void){
    fastio;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c, false);
    }
    int source, sink;
    cin >> source >> sink;

    cout << networkFlow(source, sink) << "\n";
    return 0;
}