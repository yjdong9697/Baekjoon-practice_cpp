#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main(void){
    fastio;
    string a, b;
    cin >> a >> b;

    int s_size = a.size();
    queue<int> q;
    for(int i = 0; i < s_size; i++){
        q.push(dp[a[i] - 'A']);
        q.push(dp[b[i] - 'A']);
    }

    int recur = 2 * s_size - 1;
    while(q.size() != 2){
        for(int i = 0; i < recur; i++){
            int f = q.front();
            q.pop();
            int b = q.front();
            q.push((f + b) % 10);
        }
        q.pop();
        recur--;
    }

    int result_f = q.front();
    q.pop();
    int result_b = q.back();

    cout << result_f << result_b << "\n";
    return 0;
}