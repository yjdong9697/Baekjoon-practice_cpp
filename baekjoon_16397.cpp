#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

bool visited[100000];

int main(void){
    memset(visited, 0, sizeof(visited));
    fastio;
    string n, g;
    int t;
    cin >> n >> t >> g;

    queue<string> q;
    q.push(n);
    visited[stoi(n)] = 1;
    int move_num = 0;
    bool flag = false;

    while(true){
        if(move_num > t){
            cout << "ANG" << "\n";
            return 0;
        }
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            string cur = q.front();
            q.pop();
            if(cur == g){
                flag = true;
                break;
            }

            if(stoi(cur) != 99999){
                if(!visited[stoi(cur) +1]){
                    q.push(to_string(stoi(cur) + 1));
                    visited[stoi(cur) + 1] = 1;
                }
            }
            if(stoi(cur) * 2 <= 99999){
                string temp = to_string(stoi(cur) * 2);
                for(int i = 0; i < temp.size(); i++){
                    if(temp[i] != '0'){
                        temp[i] = temp[i] - 1;
                        break;
                    }
                }
                if(!visited[stoi(temp)]){
                    q.push(to_string(stoi(temp)));
                    visited[stoi(temp)] = 1;
                }
            }
        }
        if(flag){
            cout << move_num << "\n";
            return 0;
        }
        move_num++;
    }
}