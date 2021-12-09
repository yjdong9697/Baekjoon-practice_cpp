#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int visited[100001];
int finish[100001];
int n;
int result;
vector<int> v;

void dfs(int x){
    visited[x] = 1;
    int to = v[x];
    if(!visited[to]){
        dfs(to);
    }
    else{
        if(!finish[to]){
            for(int i = to; i != x; i = v[i]) result++;
            result++;
        }
    }
    finish[x] = 1; // x의 연결 상태가 완전히 종료
    return;
}

int main(void){
    fastio;
    int t;
    cin >> t;

    while(t--){
        memset(visited, 0, sizeof(visited));
        memset(finish, 0, sizeof(finish));
        v.clear();
        result = 0;
        
        cin >> n;
        v.push_back(0);
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            v.push_back(t);
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]) dfs(i);
        }
    
        cout << n - result << "\n";
    }
    return 0;
}