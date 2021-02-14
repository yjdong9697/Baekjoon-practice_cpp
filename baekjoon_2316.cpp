#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 123456789;

const int MAX_N = 802; 

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
                if(adj[here][i] -> residual() > 0 && parent[adj[here][i] -> to] == nullptr){
                    q.push(adj[here][i] -> to);
                    parent[adj[here][i] -> to] = adj[here][i];
                }
            }
        }
        if(parent[sink] == nullptr) break; // There is no augmenting path
        // 무조건 minimum capacity가 1이므로 해당 작업은 생략해도 무방하다.
        for(int p = sink; p != source; p = parent[p] -> from){
            if(p != 1 && p != 3)parent[p] -> add_flow(1);
        }
        max_flow++;
    }
    return max_flow;
}

int main(void){
    fastio;
    int N, P;
    cin >> N >> P;

    for(int i = 1; i <= N; i++){
        add_edge(i * 2 - 2, i * 2 - 1, 1);
    }

    for(int i = 0; i < P; i++){
        int num1, num2;
        cin >> num1 >> num2;
        add_edge(num1 * 2 - 1, num2 * 2 - 2, 1);
        add_edge(num2 * 2 - 1, num1 * 2 - 2, 1);
    }

    cout << networkFlow(0, 3) << "\n";
    int n;

    return 0;
}