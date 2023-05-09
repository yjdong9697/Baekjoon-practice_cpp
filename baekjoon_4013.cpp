#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

vector<int> edge[500001];
vector<int> scc_edge[500001];
vector<int> rest_list;
stack<int> s;
stack<int> topological_sort;
int idx[500001];
int idx_low[500001];
int cash[500001];

int sccNum[500001];
int sccCash[500001];
bool sccRes[500001];
int sccMAX[500001];
int start;
int rest_num;
bool in_stack[500001];
bool rest[500001];
int visited[500001];
bool can[500001];
int cur_time = 0;
int scc_num = 0;

void dfs(int cur){
    visited[cur] = 1;
    for(int i = 0; i < scc_edge[cur].size(); i++){
        int next_node = scc_edge[cur][i];
        if(visited[next_node] == 0){
            dfs(next_node);
        }
    }
    topological_sort.push(cur);
}

void tarjan(int cur_node){
    idx[cur_node] = idx_low[cur_node] = cur_time++;
    s.push(cur_node);
    in_stack[cur_node] = 1;

    for(int i = 0; i < edge[cur_node].size(); i++){
        int next_node = edge[cur_node][i];
        if(idx[next_node] == -1){
            tarjan(next_node);
            idx_low[cur_node] = min(idx_low[cur_node], idx_low[next_node]);
        }
        else if(in_stack[next_node]){
            idx_low[cur_node] = min(idx_low[cur_node], idx[next_node]);
        }
    }
    
    if(idx[cur_node] == idx_low[cur_node]){
        int cur_scc_num = scc_num++;
        bool rest_check = false;
        int tmp;
        do{
            tmp = s.top();
            s.pop();
            in_stack[tmp] = false;
            sccNum[tmp] = cur_scc_num;
            if(rest[tmp]) rest_check = true;
            sccCash[cur_scc_num] += cash[tmp];           
        }while(!s.empty() && tmp != cur_node);

        if(rest_check) sccRes[cur_scc_num] = true;
        sccMAX[cur_scc_num] = sccCash[cur_scc_num];
    }
}

int main() {
    fastio;
    memset(sccCash, 0, sizeof(sccCash));
    memset(sccRes, 0, sizeof(sccRes));
    memset(idx, -1, sizeof(idx));
    memset(idx_low, -1, sizeof(idx_low));
    memset(in_stack, 0, sizeof(in_stack));
    memset(rest, 0, sizeof(rest));
    memset(visited, 0, sizeof(visited));
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        cash[i] = t;
    }

    cin >> start >> rest_num;
    for(int i = 0; i < rest_num; i++){
        int t;
        cin >> t;
        rest[t] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(idx[i] == -1) tarjan(i);
    }

    start = sccNum[start];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < edge[i].size(); j++){
            int next_node = edge[i][j];
            if(sccNum[i] != sccNum[next_node]){
                scc_edge[sccNum[i]].push_back(sccNum[next_node]);
            }
        }
    }

    for(int i = 0; i < scc_num; i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }
    can[start] = 1;
    while(!topological_sort.empty()){
        int cur = topological_sort.top();
        topological_sort.pop();
        if(can[cur] == 0) continue;
        for(int i = 0; i < scc_edge[cur].size(); i++){
            int next_scc = scc_edge[cur][i];
            can[next_scc] = 1;
            sccMAX[next_scc] = max(sccMAX[next_scc], sccMAX[cur] + sccCash[next_scc]);
        }
    }
    
    int result = 0;
    for(int i = 0; i < scc_num; i++){
        if(can[i] && sccRes[i] && sccMAX[i] > result){
            result = sccMAX[i];
        }
    }

    cout << result << "\n";
    return 0;
}