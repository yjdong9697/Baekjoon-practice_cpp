#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

char state[123457];
vector<vector<int> > r;
bool visited[123457];
ll num_store[123457];

ll dfs(int x){
    visited[x] = 1;
    ll sheep_count = 0;
    for(int i = 0; i < r[x].size(); i++){
        int cur = r[x][i];
        if(!visited[cur]){
            sheep_count += dfs(cur);
        }
    }
    if(state[x] == 'S') return sheep_count + num_store[x];
    else return max(sheep_count - num_store[x], 0LL);
}

int main(void){
    memset(visited, 0, sizeof(visited));
    fastio;
    int n;
    cin >> n;
    r = vector<vector<int> > (n + 1);

    state[1] = 'S';
    num_store[1] = 0LL;

    for(int i = 2; i <= n; i++){
        char v;
        ll a;
        int index;
        cin >> v >> a >> index;

        r[i].push_back(index);
        r[index].push_back(i);
        num_store[i] = a;
        state[i] = v;
    }

    cout << dfs(1) << "\n";
    return 0;
}