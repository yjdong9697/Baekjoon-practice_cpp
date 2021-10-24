#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
vector<int> v;
int N, M;
int visited[8];
int result[8];

void solve(int index){
    if(index == M){
        for(int i = 0; i < M; i++){
            if(i != M - 1) cout << result[i] << " ";
            else cout << result[i] << "\n";
        }
        return;
    }
    else{
        for(int i = 0; i < N; i++){
            if(visited[i]) continue;
            visited[i] = 1;
            result[index] = v[i];
            solve(index + 1);
            visited[i] = 0;
        }
        return;
    }
}

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(result, 0, sizeof(result));
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    solve(0);
}