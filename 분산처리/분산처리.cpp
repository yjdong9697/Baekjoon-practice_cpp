#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int t = 1;
        for(int i = 0; i < b; i++){
            t *= a;
            t %= 10;
        }
        if(t == 0) t = 10;
        cout << t << "\n";
    }
    return 0;
}