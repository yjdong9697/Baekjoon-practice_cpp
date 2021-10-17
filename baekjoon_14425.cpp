#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n, m;
    int intersect = 0;
    cin >> n >> m;

    set<string> set_value;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        set_value.insert(t);
    }

    for(int i = 0; i < m; i++){
        string t;
        cin >> t;
        if(set_value.find(t) != set_value.end()){
            intersect++;
        }
    }
    cout << intersect << "\n";
    return 0;
}