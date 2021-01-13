#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

ll dp[32][32];

ll N, L, check_num;

void dp_check(int index){
    if(index > N) return;
    if(index == 1){
        dp[index][1] = 1;
        dp[index][0] = 1;
    }
    else{
        for(int i = 1; i <= L; i++){
            if(dp[index][i] != 0) continue; // 이미 처리
            if(i == 1){
                dp[index][i] = 1;
                continue;
            }
            ll sum_result = 0;
            for(int j = 1; j <= index - 1; j++){
                if(dp[index - j][i - 1] != 0){
                    sum_result += dp[index - j][i - 1];
                }
            }
            dp[index][i] = sum_result;
        }
    }
    dp_check(index + 1);
    return;
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> check_num;
    memset(dp, 0, sizeof(dp));

    int result_store[32] = {0};

    dp_check(1);

    ll sum_store[32]; // 각 자리기준 몇개가 존재하는지

    int check_count = 0;

    while(check_num){
        for(int i = 1; i <= N; i++){
            ll temp = 0;
            for(int j = 0; j <= L - check_count; j++){
                temp += dp[i][j];
            }
            sum_store[i] = temp;
        }

        ll compare_value = 0;
        if(check_num == 2){
            result_store[1] = 1;
            break;
        }
        if(check_num == 1){
            result_store[1] = 0;
            break;
        }
        for(int i = 1; i <= N; i++){
            compare_value += sum_store[i];
            if(compare_value >= check_num){
                result_store[i] = 1;
                check_num = check_num - (compare_value - sum_store[i]);
                check_count += 1;
                break;
            }
        }
    }

    for(int i = N; i >= 1; i--){
        cout << result_store[i];
    }
    cout << "\n";
    return 0;
}