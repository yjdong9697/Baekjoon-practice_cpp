#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    if(n % 10 != 0){
        cout << -1 << "\n";
    }
    else{
        int check_1 = n / 300;
        int check_2 = (n - check_1 * 300) / 60;
        int check_3 = (n - check_1 * 300 - check_2 * 60) / 10;
        cout << check_1 << " " << check_2 << " " << check_3 << "\n";
    }

    return 0;
}