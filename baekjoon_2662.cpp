#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[21][301]; // i번째 기업까지 고려했을 때, 정확히 j만큼의 투자금액을 한 상황에서의 이익

int main(void){
    fastio;
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin >> n >> m;

    vector<int> b[m + 1];

    for(int i = 1; i <= m; i++){
        b[i].push_back(0); // Trash data
    }

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        for(int j = 1; j <= m; j++){
            int v;
            cin >> v;
            b[j].push_back(v);
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + b[i][k]);
            }
        }
    }

    int max_result = -1;
    int max_index;

    for(int i = 0; i <=n; i++){
        if(max_result < dp[m][i]){
            max_result = dp[m][i];
            max_index = i;
        }
    }
    cout << max_result << "\n";
    
    vector<int> result;

    for(int i = m; i > 1; i--){
        for(int j = 0; j <= n; j++){
            if(max_result == dp[i - 1][n - j] + b[i][j]){
                result.push_back(j);
                max_result -= b[i][j];
                n -= j;
                break;
            }
        }
    }

    for(int j = 0; j <= n; j++){
        if(max_result == b[1][j]){
            result.push_back(j);
            break;
        }
    }

    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}