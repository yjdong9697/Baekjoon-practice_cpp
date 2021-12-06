#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    
    int result = 2;

    for(int i = 2; i <= n; i++){
        result += (i / 2) + 1;
    }
    cout << result << "\n";
    return 0;
}