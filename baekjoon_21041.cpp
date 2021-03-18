#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int main(void){
    fastio;
    int n;
    int data[301][301];
    vector<int> value(100001, 0);
    memset(data, 0, sizeof(data));

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int temp;
            cin >> temp;
            data[i][j] = temp;
        }
    }
    int max_value = -1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int check_value = data[i][j];
            if(value[check_value] == 0){
                value[check_value] = j;
            }
            else{
                if(value[check_value] <= j){
                    max_value = max(check_value, max_value);
                }
                else{
                    value[check_value] = j;
                } 
            }
        }
    }

    cout << max_value << "\n";
    return 0;
}