#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    vector<int> v(4);
    for(int i = 1; i <= 3; i++){
        v[i]= i;
    }

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int v1, v2;
        cin >> v1 >> v2;
        int temp = v[v1];
        v[v1] = v[v2];
        v[v2] = temp;
    }

    for(int i = 1; i <= 3; i++){
        if(v[i] == 1) cout << i << "\n";
    }
    return 0;
}