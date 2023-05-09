#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
vector<int> edge[10001];
int idx[10001];
int idx_low[10001];
bool in_stack[10001];
bool scc_check[10001];
int scc_value[10001];
int scc_num = 0;
stack<int> s;
int cur_time = 0;

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
        while(s.top() != cur_node){
            int tmp = s.top();
            s.pop();
            scc_value[tmp] = scc_num;
            in_stack[tmp] = 0;
        }
        int tmp = s.top();
        s.pop();
        scc_value[tmp] = scc_num;
        in_stack[tmp] = 0;
        scc_num++;
    }
}

int main() {
    fastio;
    memset(idx, -1, sizeof(idx));
    memset(idx_low, -1, sizeof(idx_low));
    memset(in_stack, 0, sizeof(in_stack));
    memset(scc_check, 0, sizeof(scc_check));
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }

    for(int i = 1; i <= v; i++){
        if(idx[i] == -1) tarjan(i);
    }

 
    cout << scc_num << "\n";
    for(int it = 0; it < scc_num; it++){
        int cur_scc = -1;
        for(int i = 1; i <= v; i++){
            if(cur_scc == -1 && scc_check[scc_value[i]] == 0){
                scc_check[scc_value[i]] = 1;
                cur_scc = scc_value[i];
                cout << i << " ";
            }
            else{
                if(cur_scc == scc_value[i]){
                    cout << i << " ";
                }
            }
        }
        cout << "-1\n";
    }
    return 0;
}