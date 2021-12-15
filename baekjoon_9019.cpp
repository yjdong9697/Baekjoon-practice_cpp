#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int visited[10001];
string oper[4] = {"D", "S", "L", "R"};

int main(void){
    fastio;
    int t;
    cin >> t;

    while(t--){
        memset(visited, 0, sizeof(visited));
        int a, b;
        cin >> a >> b;
        queue<pair<int, string> > q;
        q.push(make_pair(a, ""));
        visited[a] = 1;
        while(true){
            int cur = q.front().first;
            string cur_oper = q.front().second;
            q.pop();
            if(cur == b){
                cout << cur_oper << "\n";
                break;
            }

            for(int i = 0; i < 4; i++){
                int num = cur;
                if(i == 0) num = (num * 2) % 10000;
                else if(i == 1) num = (num - 1 + 10000) % 10000;
                else if(i == 2) num = (num % 1000) * 10 + num / 1000;
                else num = num / 10 + (num % 10) * 1000;
                if(!visited[num]){
                    q.push(make_pair(num, cur_oper + oper[i]));
                    visited[num] = 1;
                }
            }
        }
    }
    return 0;
}