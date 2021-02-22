#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef pair<int,int> pii;
const int INF  = 123456789;

int dp[1000001];

void dp_checker(int start, int length){
    for(int i = 1; i <= length; i++){
        if(start + i < 1000001) dp[start + i] = min(dp[start + i], dp[start] + 1);        
    }
}

bool compare(pii temp1, pii temp2){
    if(temp1.first == temp2.first){
        return temp1.second > temp2.second;
    }
    else return temp1.first < temp2.first;
}

int main(void){
    fastio;
    fill(dp, dp + 1000001, INF);

    int N, M;
    cin >> N >> M;

    int carry_temp[100000][2];
    int first_start;
    int first_length;

    for(int i = 0; i < N; i++){
        if(i == 0) cin >> first_start;
        else cin >> carry_temp[i - 1][0];
    }

    for(int i = 0; i < N; i++){
        if(i == 0) cin >> first_length;
        else cin >> carry_temp[i - 1][1];
    }

    for(int i = 0; i <= first_length; i++){
        if(first_start + i < 1000001) dp[first_start + i] = 0;
        else break;
    }

    for(int i = 0; i < N - 1; i++){
        dp_checker(carry_temp[i][0], carry_temp[i][1]);
    }

    if(dp[M] >= INF){
        cout << "-1\n";
        return 0;
    }
    else{
        cout << dp[M] << "\n";
        return 0;
    }
}