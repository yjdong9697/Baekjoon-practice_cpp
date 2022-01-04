#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;

int dp[101][10][1 << 10];

int count(int cur_n, int last_num, int visited){
    int& ret = dp[cur_n][last_num][visited];
    // Base Case
    if(cur_n == n){
        if(visited == (1 << 10) - 1) return ret = 1;
        else return ret = 0;
    }
    if(ret != -1) return ret;

    int prev = last_num - 1;
    int front = last_num + 1;
    int result = 0;
    if(0 <= prev && prev <= 9){
        int next = visited | (1 << prev);
        result += count(cur_n + 1, prev, next);
        result %= 1000000000;
    }
    if(0 <= front && front <= 9){
        int next = visited | (1 << front);
        result += count(cur_n + 1, front, next);
        result %= 1000000000;
    }
    return ret = result;
}

int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    cin >> n;

    int result = 0;

    for(int i = 1; i < 10; i++){
        result += count(1, i, 1 << i);
        result %= 1000000000;
    }

    cout << result << "\n";
    return 0;
}