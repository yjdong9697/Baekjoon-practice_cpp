#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};


int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    double k = (double) a / b;
    
    if(a % b == 0){
        cout << 0 << "\n";
    }
    else{
        for(int i = 0; i < c; i++){
            a %= b;
            a *= 10;
        }
        cout << a / b << "\n";
    }
    return 0;


    return 0;
}