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
    int p1, s1, s2, p2;
    cin >> p1 >> s1;
    cin >> s2 >> p2;
    if(p1 + p2 > s1 + s2){
        cout << "Persepolis\n";
        return 0;
    }
    else if(p1 + p2 < s1 + s2){
        cout << "Esteghlal\n";
        return 0;
    }
    else{
        if(s1 == p2) cout << "Penalty\n";
        else if(s1 > p2){
            cout << "Esteghlal\n";
        }
        else cout << "Persepolis\n";
        return 0;
    }
}