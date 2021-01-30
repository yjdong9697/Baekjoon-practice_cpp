#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int check_count = 1;
int dp[129][129];

int move_value[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};

int cor_check(int fl, int fr, int sl, int sr, int x, int y){
    if(fl <= x && x <= (fl + fr) / 2){
        if(sl <= y && y <= (sl + sr) / 2){
            return 0;
        }
        else return 2;
    }
    else{
        if(sl <= y && y <= (sl + sr) / 2){
            return 1;
        }
        else return 3;

    }
}

// fr, sr는 포함
void fill_function(int fl, int fr, int sl, int sr, int x, int y){
    // Base case
    if(fr - fl == 1 && sr - sl == 1){
        for(int i = 0; i < 4; i++){
            int dx = fl + move_value[i][0];
            int dy = sl + move_value[i][1];
            if(dx != x || dy != y){
                dp[dx][dy] = check_count;
            }
        }
        check_count++;
        return;
    }
    int current_blank = cor_check(fl, fr, sl, sr, x, y);
    int check_temp = check_count;
    check_count++;
    for(int i = 0; i < 4; i++){      
        int dx = (fl + fr) / 2 + move_value[i][0];
        int dy = (sl + sr) / 2 + move_value[i][1];
        if(current_blank == i){
            if(i == 0) fill_function(fl, dx, sl, dy, x, y);
            else if(i == 1) fill_function(dx, fr, sl, dy, x, y);
            else if(i == 2) fill_function(fl, dx, dy, sr, x, y);
            else fill_function(dx, fr, dy, sr, x, y);
        }
        else{
            if(dp[dx][dy] != -1) dp[dx][dy] = check_temp;
            if(i == 0) fill_function(fl, dx, sl, dy, dx, dy);
            else if(i == 1) fill_function(dx, fr, sl, dy, dx, dy);
            else if(i == 2) fill_function(fl, dx, dy, sr, dx, dy);
            else fill_function(dx, fr, dy, sr, dx, dy);
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    int K;
    cin >> K;

    int x_cor, y_cor;
    cin >> x_cor >> y_cor;
    x_cor--; y_cor--; // 0으로 시작하게끔 변환
    dp[x_cor][y_cor] = -1; // 하수구 위치
    fill_function(0, pow(2, K) - 1, 0, pow(2, K) - 1, x_cor, y_cor);

    for(int i = pow(2, K) - 1; i >= 0; i--){
        for(int j = 0; j < pow(2, K); j++){
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}