#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
set<string> visited;

int main(void){
    string v = "";
    string end = "123456780";

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int t;
            cin >> t;
            v += to_string(t);
        }
    }
    int m[9][4] = {{-1, 3, -1, 1},
                   {-1, 4, 0, 2},
                   {-1, 5, 1, -1},
                   {0, 6, -1, 4},
                   {1, 7, 3, 5},
                   {2, 8, 4, -1},
                   {3, -1, -1, 7},
                   {4, -1, 6, 8},
                   {5, -1, 7, -1}};

    queue<string> q;
    q.push(v);
    visited.insert(v);

    int move_num = 0;
    bool flag = false;
    while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            string cur = q.front();
            if(cur == end){
                flag = true;
                break;
            }
            
            int zero_pos;

            for(int i = 0; i < cur.size(); i++){
                if(cur[i] == '0'){
                    zero_pos = i;
                    break;
                }
            }

            q.pop();

            for(int j = 0; j < 4; j++){
                string next = cur;
                int next_index = m[zero_pos][j];
                if(next_index == -1) continue;

                next[zero_pos] = cur[next_index];
                next[next_index] = cur[zero_pos];

                if(visited.find(next) == visited.end()){
                    q.push(next);
                    visited.insert(next);
                }

            }
        }
        if(flag){
            cout << move_num << "\n";
            return 0;
        }
        move_num++;

    }

    // No case exist;
    cout << -1 << "\n";
    return 0;
}