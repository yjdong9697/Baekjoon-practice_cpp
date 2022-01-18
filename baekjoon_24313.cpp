#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};


int main() {
    fastio;
    int a_1, a_2;
    cin >> a_1 >> a_2;
    int c, n_0;
    cin >> c >> n_0;
    if(a_1 > c){
        cout << 0 << "\n";
        return 0;
    }

    int value_1 = a_1 * n_0 + a_2;
    int value_2 = n_0 * c;
    
    if(value_1 <= value_2){
        cout << 1 << "\n";
    }
    else cout << 0 << "\n";
    return 0;
}