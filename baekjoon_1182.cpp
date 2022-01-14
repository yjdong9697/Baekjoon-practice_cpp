#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};


int main() {
    fastio;
    int n, s;
    cin >> n >> s;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int result = 0;

    for(int i = 1; i < 1 << n; i++){
        int cur_sum = 0;
        for(int j = 0; j < n; j++) if(i & (1 << j)) cur_sum += v[j];
        if(cur_sum == s) ++result;
    }
    
    cout << result << "\n";
    return 0;   
}