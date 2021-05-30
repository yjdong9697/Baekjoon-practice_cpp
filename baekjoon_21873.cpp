#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;


int main(void){
    fastio;
    int n;
    cin >> n;

    cout << n * n + 2 * n << "\n";

    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            for(int j = 1; j <= i; j++){
                cout << 1 << " " << j << "\n";
            }
        }
        else{
            for(int j = 1; j <= i; j++){
                cout << 2 << " " << j << "\n";
            }
        }
    }
    
    for(int j = 1; j <= n; j++){
        cout << (1 + (n + 1) % 2) << " " << j << "\n";
    }

    for(int i = 1; i <= n; i++){
        if((i + n + 1) % 2 == 0){
            for(int j = i; j <= n; j++){
                cout << 1 << " " << j << "\n";
            }
        }
        else{
            for(int j = i; j <= n; j++){
                cout << 2 << " " << j << "\n";

            }
        }
    }

    return 0;
}