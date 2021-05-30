#include <bits/stdc++.h>
#define fasio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1){
        cout << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
    }  
    else{
        cout <<  2 * (n - 1) << "\n";
        for(int i = 1; i <= n; i++){
            cout << 1 << " " << i << "\n";
        }
        for(int i = 2; i < n; i++){
            cout << n << " " << i << "\n";
        }
    }
    return 0;
}