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
    int p, q;
    cin >> p >> q;
    // p : 10만명당 확진자수
    // q : 위중증
    if(p <= 50 && q <= 10){
        cout << "White\n";
    }
    else if(q > 30){
        cout << "Red\n";
    }
    else{
        cout << "Yellow\n";
    }
    return 0;
}