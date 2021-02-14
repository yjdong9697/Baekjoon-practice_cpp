#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int MAX_N = 10002;

using namespace std;
int K, N;
struct edge{
    int from, to;
    bool capacity, flow;
    edge* reverse_edge;
    edge(int u, int v, int c) : from(u), to(v), capacity(c), flow(false)
    {}

    int residual(){
        return capacity - flow;
    }

    void add_flow(){
        flow = true;
        reverse_edge -> flow = false;
    }
};

void add_edge(int u, int v, int c, vector<edge*> *adj, bool dir = true){
    edge* e1 = new edge(u, v, c);
    edge* e2 = new edge(v, u, dir ? 0 : c);
    e1 -> reverse_edge = e2;
    e2 -> reverse_edge = e1;
    adj[u].push_back(e1);
    adj[v].push_back(e2);
    return;
}

vector<edge*> adj[MAX_N];
vector<int> print_store[100]; // 프린트하는 것 저장하는 목적

bool networkFlow(int source, int sink){
    int aug_path_count = 0;
    while(true){
        vector<edge*> parent(MAX_N, nullptr);
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == nullptr){
            int here = q.front(); q.pop();
            for(int p = 0; p < adj[here].size(); p++){
                if(adj[here][p]->residual() > 0 && parent[adj[here][p] ->to] == nullptr){
                    q.push(adj[here][p] -> to);
                    parent[adj[here][p] -> to] = adj[here][p];
                }
            }
        }
        if(parent[sink] == nullptr) break;

        for(int p = sink; p != source; p = parent[p] -> from){
            if((p + 2) / 2 != (parent[p] -> from + 2) / 2) print_store[aug_path_count].push_back((p + 2) / 2);
            if(p != 1 && p != 3) parent[p] -> add_flow();
        }
        print_store[aug_path_count].push_back(1);

        aug_path_count++;
        if(aug_path_count == K) return true;
    }
    return false;
}

int main(void){
    int case_num = 1;
    
    while(true){
        cin >> K >> N;
        if(K == 0 && N == 0) return 0; // 종료인 상황

        for(int i = 1; i <= N; i++){
            add_edge(i * 2 - 2, i * 2 - 1, 1, adj);
        }

        for(int i = 1; i <= N; i++){
            int path_num; char check_data;
            while(true){
                scanf("%d%c", &path_num, &check_data);
                add_edge(i * 2 - 1, path_num * 2 - 2, 1, adj);
                if(check_data == '\n') break;
            }
        }
        cout << "Case " << case_num << ":\n";
        if(networkFlow(0, 3)){
            for(int i = 0; i < K; i++){
                for(int j = print_store[i].size() -1; j >= 0; j--){
                    cout << print_store[i][j] << " ";
                }
                cout << "\n";
            }

        }
        else cout << "Impossible\n";
        cout << "\n";

        // Dummy data reset
        for(int i = 0; i < MAX_N; i++){
            adj[i].clear();
        }
        for(int i = 0; i < 100; i++){
            print_store[i].clear();
        }
        case_num++;
    }
}