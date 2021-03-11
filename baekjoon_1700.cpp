#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
#define INF 987654321

int main(void){
    fastio;
    int n, k;
    cin >> n >> k;
    vector<queue<int> > dp(k + 1);
    queue<int> data;
    
    for(int i = 1; i <= k; i++){
        int temp;
        cin >> temp;
        dp[temp].push(i);
        data.push(temp);
    }

    vector<int> plug(k + 1, 0);

    // 일단 플러그에 다 꽂아둠
    while(n){
        if(!data.empty()){
            int cur = data.front(); data.pop();
            dp[cur].pop();
            if(plug[cur] == 0){
                plug[cur] = 1;
                n--;
            }
        }
        else break;
    }

    int change_num = 0;
    while(!data.empty()){
        int cur = data.front(); data.pop();
        dp[cur].pop();
        // 이미 꼽혀 있는 경우
        if(plug[cur] == 1) continue;
        else{
            int max_index = -1;
            int max_value = -1;
            for(int i = 1; i <= k; i++){
                if(plug[i] == 0) continue; // plug 된 것만 검토
                int cmp;
                // 뒤에 더이상 등장하지 않는 경우
                if(dp[i].empty()){
                    cmp = INF;
                }
                else cmp = dp[i].front();
                if(cmp > max_value){
                    max_value = cmp;
                    max_index = i;
                }
            }
            plug[max_index] = 0;
            plug[cur] = 1;
            change_num++;
        }
    }
    cout << change_num << "\n";
    return 0;
}