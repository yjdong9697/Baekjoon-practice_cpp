#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    set<string> s;
    int n, k;
    cin >> n >> k;

    string ans = "";

    for(int i = 1; i <= n; i++){
        ans += to_string(i);
    }

    queue<string> q;

    string input = "";

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        input += to_string(t);
    }
    q.push(input);

    int move_num = 0;
    while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            string cur = q.front();
            q.pop();
            if(cur == ans){
                cout << move_num << "\n";
                return 0;
            }
            
            for(int j = 0; j <= cur.size() - k; j++){
                string cmp = cur;
                reverse(cmp.begin() + j, cmp.begin() + j + k);
                if(s.find(cmp) == s.end()){
                    q.push(cmp);
                    s.insert(cmp);
                }
            }
        }
        move_num++;
    }
    cout << -1 << "\n";
    return 0;
}