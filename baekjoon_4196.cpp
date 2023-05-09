#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
vector<int> edge[100001];
stack<int> s;
int scc_num;
int idx[100001];
int idx_low[100001];
bool in_stack[100001];
int scc_val[100001];
int indegree[100001];
int cur_time;

void tarjan(int cur_node){
    idx[cur_node] = idx_low[cur_node] = cur_time++;
    in_stack[cur_node] = 1;
    s.push(cur_node);

    for(int i = 0; i < edge[cur_node].size(); i++){
        int next_node = edge[cur_node][i];
        if(idx[next_node] == -1){
            tarjan(next_node);
            idx_low[cur_node] = min(idx_low[cur_node], idx_low[next_node]);
        }
        else if(in_stack[next_node] == 1){
            idx_low[cur_node] = min(idx_low[cur_node], idx[next_node]);
        }
    }
    if(idx[cur_node] == idx_low[cur_node]){
        while(s.top() != cur_node){
            int tmp = s.top();
            s.pop();
            scc_val[tmp] = scc_num;
            in_stack[tmp] = 0;
        }
        int tmp = s.top();
        s.pop();
        scc_val[tmp] = scc_num;
        in_stack[tmp] = 0;
        scc_num++;
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        int n, m;
        cin >> n >> m;
        memset(idx, -1, sizeof(idx));
        memset(idx_low, -1, sizeof(idx_low));
        memset(in_stack, 0, sizeof(in_stack));
        memset(indegree, 0, sizeof(indegree));
        scc_num = 0;
        cur_time = 0;
        for(int i = 1; i <= n; i++){
            edge[i].clear();
        }
        
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
        }
        for(int i = 1; i <= n; i++){
            if(idx[i] == -1) tarjan(i);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < edge[i].size(); j++){
                int next_node = edge[i][j];
                if(scc_val[i] != scc_val[next_node]){
                    indegree[scc_val[next_node]]++;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < scc_num; i++){
            if(indegree[i] == 0) cnt++;
        }   
        cout << cnt << "\n";
    }
    
    return 0;
}