#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n, m, p;
int visited[100001];
int v[100001];
int r[100001];

int dfs(int c){
    visited[c] = 1;
    if(v[c] == -1) return 0;
    int cur = r[v[c]];
    int result = 0;
    if(!visited[cur]){
        int val = dfs(cur);
        if(val == -1) return -1;
        else
            result += val;
    }
    else return -1;
    return result + 1;
}

int main(void){
    fastio;
    memset(v, -1, sizeof(v));
    memset(visited, 0, sizeof(visited));
    cin >> n >> m >> p;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        r[i] = a;
        if(v[b] == -1) v[b] = i;
    }

    cout << dfs(p) << "\n";
    return 0;
}