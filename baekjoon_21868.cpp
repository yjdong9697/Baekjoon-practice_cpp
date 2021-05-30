#include <bits/stdc++.h>
#define fasio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int a, b;

int f_value(int x){
    return a*x + b;
}

int main(void){
    int e_1, e_2;
    cin >> e_1 >> e_2;

    cin >> a >> b;
    int x;
    cin >> x;

    int value = f_value(x);

    cout << value << "\n";
    if(a == 0){
        cout << 0 << " " << 0 << "\n";
    }
    else{
        cout << e_1 << " " << abs(a) * e_2 << "\n";
    }
    return 0;
    
}