#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[19];

int main(void){
    fastio;
    int n;
    string buffer;
    cin >> n;
    getline(cin, buffer);
    for(int i = 1; i <= n; i++){
        memset(dp, 0, sizeof(dp)); // Initialization
        string s;
        getline(cin, s);
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'w'){
                dp[0] += 1;
            }
            else if(s[j] == 'e'){
                dp[1] += dp[0];
                dp[6] += dp[5];
                dp[14] += dp[13];

            }
            else if(s[j] == 'l'){
                dp[2] += dp[1];

            }
            else if(s[j] == 'c'){
                dp[3] += dp[2];
                dp[11] += dp[10];

            }
            else if(s[j] == 'o'){
                dp[4] += dp[3];
                dp[9] += dp[8];
                dp[12] += dp[11];

            }
            else if(s[j] == 'm'){
                dp[5] += dp[4];
                dp[18] += dp[17];

            }
            else if(s[j] == 't'){
                dp[8] += dp[7];

            }
            else if(s[j] == 'd'){
                dp[13] += dp[12];

            }
            else if(s[j] == 'j'){
                dp[16] += dp[15];

            }
            else if(s[j] == 'a'){
                dp[17] += dp[16];

            }
            else if(s[j] == ' '){
                dp[7] += dp[6];
                dp[10] += dp[9];
                dp[15] += dp[14];
            }
            else continue;
        }
        int result = dp[18] % 10000;
        cout << "Case #" << i << ": ";
        int recur = 4 - to_string(result).size();
        for (int i = 0; i < recur; i++){
            cout << "0";
        }
        cout << result << "\n";
    }
    return 0;
}