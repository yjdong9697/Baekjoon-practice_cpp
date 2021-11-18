#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int a_1, a_2, a_3;
    int b_1, b_2, b_3;
    cin >> a_1 >> a_2 >> a_3;
    cin >> b_1 >> b_2 >> b_3;

    cout << b_1 - a_3 << " " << b_2 / a_2 << " " << b_3 - a_1 << "\n";
    return 0;   
}