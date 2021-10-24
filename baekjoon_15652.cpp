#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int result[8]; // Print value
int n, m;

void solve(int cur, int val){
    if(val == m){
        for(int i = 0; i < m; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = cur; i <= n; i++){
        result[val] = i;
        solve(i, val + 1);
    }
    return;
}

int main(void){
    fastio;
    cin >> n >> m;
    solve(1, 0);
    return 0;
}