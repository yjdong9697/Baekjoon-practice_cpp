#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};


int main() {
    fastio;
    vector<int> a, b;
    int sum_value = 0;
    for(int i = 0; i < 4; i++){
        int t;
        cin >> t;
        a.push_back(t);
        sum_value += t;
    }
    for(int i = 0; i < 2; i++){
        int t;
        cin >> t;
        b.push_back(t);
        sum_value += t;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    sum_value -= (a[0] + b[0]);
    cout << sum_value << "\n";
    return 0;   
}