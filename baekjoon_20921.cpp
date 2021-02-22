#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main(void){
    fastio;
    int n, k;
    cin >> n >> k;

    int temp[n];
    memset(temp, -1, sizeof(temp)); // -1로 초기화
    int current_num = 1;
    for(int i = n - 1; i >= 0; i--){
        if(k == 0) break;
        if(k - i >= 0){
            temp[i] = current_num;
            k -= i;
            current_num++;
        }
        else{
            for(int i = k; i >= 0; i--){
                if(temp[i] == -1){
                    temp[i] = current_num;
                    k -= i;
                    current_num++;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(temp[i] == -1){
            temp[i] = current_num;
            current_num++;
        }
    }
    

    for(int i = 0; i < n; i++){
        cout << temp[i] << " ";
    }
    cout << "\n";
    return 0;
}