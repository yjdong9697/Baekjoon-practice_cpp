#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    unsigned long long n, k;
    cin >> n >> k;

    unsigned long long result = (2 * n + 1) * (2 * n + 1);
    
    if(k % 2 == 1){
        if((k - 1) / 2 <= n) result -= (n - (k - 1) / 2) * (n - (k - 1) / 2 + 1) * 2;
        
    }
    else{
        if(k / 2 <= n) result -= (n - k / 2) * (n - k / 2 + 1) * 2 + 2 * n + 1;
    }

    cout << result << "\n";

    return 0;
}