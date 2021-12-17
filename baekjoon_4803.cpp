#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
bool visited[501];
vector<vector<int> > r;

int edge_count;
int dfs(int x){
    visited[x] = 1;
    int comp_num = 0;
    for(int i = 0; i < r[x].size(); i++){
        edge_count++;
        int cur = r[x][i];
        if(!visited[cur]){
            comp_num += dfs(cur);
        }
    }
    return comp_num + 1;
}

int main(void){
    fastio;
    int case_num = 1;
    while(true){
        memset(visited, 0, sizeof(visited));
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        r = vector<vector<int> > (n + 1);

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            r[a].push_back(b);
            r[b].push_back(a);
        }

        int tree_num = 0;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                edge_count = 0;
                int node_count = dfs(i);
                if(edge_count / 2 == node_count - 1) tree_num++;
            }
        }

        if(tree_num == 0){
            cout << "Case " << case_num << ": No trees.\n";
        }
        else if(tree_num == 1){
            cout << "Case " << case_num << ": There is one tree.\n";

        }
        else{
            cout << "Case " << case_num << ": A forest of " << tree_num << " trees.\n";

        }
        case_num++;
    }

}