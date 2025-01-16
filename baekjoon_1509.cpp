#include <bits/stdc++.h>

using namespace std;

int pelindrom[2500][2500];
int dp[2500];
string s;

int main(void){
    memset(pelindrom, 0, sizeof(dp));
    cin >> s;
    int n = s.size();
    
    for(int j = 0; j < n; j++){
        pelindrom[j][j] = 1;
        for(int i = 0; i < j; i++){
            if(s[i] == s[j]){
                if(i == j - 1 || i == j - 2){
                    pelindrom[i][j] = 1;
                }
                else if(pelindrom[i + 1][j - 1] == 1){
                    pelindrom[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < 2500; i++){
        dp[i] = 987654321;
    }

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(pelindrom[j][i] == 1){
                if(j == 0){
                    dp[i] = 1;
                }
                else{
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[s.size() - 1] << "\n";

    return 0;
}