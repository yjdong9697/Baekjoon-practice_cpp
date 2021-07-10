#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    vector<int> v(21);
    for(int i = 1; i <= 20; i++){
        v[i]= i;
    }

    for(int i = 1; i <= 10; i++){
        int s, e;
        cin >> s >> e;
        reverse(v.begin() + s, v.begin() + e + 1);
    }

    for(int i = 1; i <= 20; i++){
        cout << v[i];
        if(i != 20){
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}