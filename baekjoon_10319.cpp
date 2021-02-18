#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MAX_N = 1002001;
int n;
int start, g, s; // i : 처음에 있는 장소(Source), g : 사람의 수, s : 감염까지 걸리는 시간

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
        queue<pii> q;
        q.push(make_pair(source, 0));
        int cost_temp;
        while(!q.empty() && parent[sink] == nullptr){
            int here = q.front().first;
            int cost = q .front().second;
            q.pop();
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i] -> to;
                if(adj[here][i] -> residual() > 0 && parent[there] == nullptr){
                    q.push(make_pair(there, cost + 1));
                    parent[there] = adj[here][i];
                }
                if(parent[sink] != nullptr){
                    cost_temp = cost;
                }
            }
        }
        if(parent[sink] == nullptr) break;
        if(cost_temp > s) break; // 이미 bfs에서 만족하는 케이스를 넘은 경우 (무조건 뒤는 더 cost가 크므로 break`)
        int amount = INF;
        for(int p = sink; p != source; p = parent[p] -> from){
            amount = min(amount, parent[p] -> residual());
        }
        for(int p = sink; p != source; p = parent[p] -> from){
            parent[p] -> add_flow(amount);
        }
        max_flow += (s - cost_temp + 1) * amount;
    }
    return max_flow;
}

int main(void){
    fastio;
    int test_case;
    cin >> test_case;

    for(int i = 0; i < test_case; i++){
        cin >> n;
        cin >> start >> g >> s;
        int m; // 병원~~
        cin >> m;
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            add_edge(temp, 1002000, INF);
        }

        int edge_num;
        cin >> edge_num;

        for(int j = 0; j < edge_num; j++){
            int from, to, capacity, cost;
            cin >> from >> to >> capacity >> cost;
            if(cost == 1){
                add_edge(from, to, capacity);
                continue;
            } 
            add_edge(from, 1001 + 1000 * j, capacity);
            for(int k = 0; k < cost - 2; k++){
                add_edge(1001 + 1000 * j + k, 1001 + 1000 * j + k + 1, capacity);
            }
            add_edge(1001 + 1000 * j + cost - 2, to, capacity);
        }
        int result_value = networkFlow(start, 1002000);
        if(result_value > g) cout << g << "\n";
        else cout << result_value << "\n";
        for(int i = 0; i < MAX_N; i++){
            adj[i].clear();
        }
    }

    return 0;
}