#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321;

using namespace std;
int R, C;

int main(void){
    fastio;
    cin >> R >> C;
    int map[1001][1001];

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }

    // 홀수인 경우(전부 다 도는 것이 가능한 상황)
    if(R % 2 == 1){
        for(int i = 0; i < R; i++){
            if(i % 2 == 0){
                for(int j = 0; j < C - 1; j++){
                    cout << "R";
                }
                if(i != R - 1) cout << "D"; // 맨 마지막에는 내려자기 않음
            }
            else{
                for(int j = 0; j < C - 1; j++){
                    cout << "L";
                }
                if(i != R - 1) cout << "D"; // 맨 마지막에는 내려가지 않음
            }
        }
        cout << "\n";
        return 0;
    }
    else{
        if(C % 2 == 1){
            for(int i = 0; i < C; i++){
                if(i % 2 == 0){
                    for(int j = 0; j < R - 1; j++){
                        cout << "D";
                    }
                    if(i != C - 1) cout << "R"; // 맨 마지막에는 오른쪽을 가지 않음
                }
                else{
                    for(int j = 0; j < R - 1; j++){
                        cout << "U";
                    }
                    if(i != C - 1) cout << "R"; // 맨 마지막에는 오른쪽을 가지 않음
                }
            }
            cout << "\n";
            return 0;
        }
        else{
            int min_value = INF;
            int min_x;
            int min_y;
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if((i + j) % 2 == 1){
                        if(min_value > map[i][j]){
                            min_value = map[i][j];
                            min_x = i;
                            min_y = j;
                        }
                    }
                }
            }

            for(int i = 0; i < (min_x / 2) * 2; i++){
                if(i % 2 == 0){
                    for(int j = 0; j < C - 1; j++){
                        cout << "R";
                    }
                    cout << "D";
                }
                else{
                    for(int j = 0; j < C - 1; j++){
                        cout << "L";
                    }
                    cout << "D";
                }
            }

            for(int j = 0; j < C; j++){
                if(min_y < j){
                    if(j % 2 == 0){
                        cout << "U";
                    }
                    else cout << "D";
                }
                else if(min_y > j){
                    if(j % 2 == 0){
                        cout << "D";
                    }
                    else cout << "U";
                }
                if(j != C - 1) cout << "R";
            }
            if((min_x / 2) * 2 + 1 != R - 1) cout << "D";

            for(int i = 0; i < R - ((min_x / 2) * 2 + 1) - 1; i++){
                for(int j = 0; j < C - 1; j++){
                    if(i % 2 == 0) cout << "L";
                    else cout << "R";
                }
                if(i != R - ((min_x / 2) * 2 + 1) - 2) cout << "D";
            }
            cout << "\n";
            return 0;
        }
    }
}