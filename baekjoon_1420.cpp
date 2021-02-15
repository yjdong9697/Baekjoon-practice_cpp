#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
const int MAX_N = 20002;
int N, M;

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
                    q.push(there);
                    parent[there] = adj[here][i];
                }
            }
        }
        if(parent[sink] == nullptr) break; // Fail to finding Augmenting path
        // 어차피 capacity는 1이므로 최소 residual 구하는 과정은 생략^^
        for(int p = sink; p != source; p = parent[p] -> from){
            // source와 sink는 정점분할하지 말아야 한다.(1번만 지나갈 수 있는 상황이 아니다)
            if(p != sink && p != source + 1) parent[p] -> add_flow(1);
        }
        max_flow++;
    }
    return max_flow;
}

bool available(int i, int j, int dir){
    // 오른쪽 체크
    if(dir == 0){
        if(j + 1 < M) return true;
        else return false;
    }
    else{
        if(i + 1 < N) return true;
        else return false;
    }

}

int main(void){
    fastio;
    cin >> N >> M;
    int source, sink;
    string data_store[N];

    if(N == 1 && M == 1){
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;

        data_store[i] = temp;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            add_edge((i * M + j) * 2, (i * M + j) * 2 + 1, 1);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            bool check_value = true;
            if(data_store[i][j] == 'K') source = i * M + j;
            else if(data_store[i][j] == 'H') sink = i * M + j;
            else if(data_store[i][j] == '#') continue;
            else check_value = false;
            // 오른쪽 체크
            if(available(i, j, 0)){
                if(data_store[i][j + 1] != '#'){
                    add_edge((i * M + j) * 2 + 1, (i * M + j + 1) * 2, 1);
                    add_edge((i * M + j + 1) * 2 + 1, (i * M + j) * 2, 1);

                    if(check_value == true && data_store[i][j + 1] != '.'){
                        cout << "-1\n";
                        return 0;
                    }
                }   
            }
            if(available(i, j, 1)){
                if(data_store[i + 1][j] != '#'){
                    add_edge((i * M + j) * 2 + 1, ((i + 1) * M + j) * 2, 1);
                    add_edge(((i + 1) * M + j) * 2 + 1, (i * M + j) * 2, 1);
                    if(check_value == true && data_store[i + 1][j] != '.'){
                        cout << "-1\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << networkFlow(source * 2, sink * 2 + 1) << "\n";
    return 0;
}