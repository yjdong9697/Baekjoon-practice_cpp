#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b + c != 180) cout << "Error\n";
    else{
        if(a == 60 && b == 60) cout << "Equilateral\n";
        else{
            if(a == b || b == c || c == a) cout << "Isosceles\n";
            else cout << "Scalene\n";
        }
    }
    return 0;
}