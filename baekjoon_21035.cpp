#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int data[51][51];
    memset(data, 0, sizeof(data));

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> data[i][j];
        }
    }

    int value = 0;
    cin >> value;
    for(int i = 0; i < value; i++){
        string check;
        cin >> check;
        if(check == "row"){
            int n1, n2;
            cin >> n1 >> n2;
            for(int i = 1; i <= m; i++){
                data[n1][i] += n2;
            }
        }
        else{
            int n1, n2;
            cin >> n1 >> n2;
            for(int i = 1; i <= n; i++){
                data[i][n1] += n2;
            }
        }
    }

    int max_value = - 1;
    int min_value = 987654321;
    int sum_value = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            if(data[i][j] > max_value){
                max_value = data[i][j];
            }
            if(data[i][j] < min_value){
                min_value = data[i][j];
            }
            sum_value += data[i][j];

        }
    }

    cout << sum_value << " " <<min_value << " " <<max_value << "\n";
    return 0;
}