#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n, m;
    map<string, string> s;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        s[a] = b;
    }

    for(int i = 0; i < m; i++){
        string value;
        cin >> value;
        cout << s[value] << "\n";
    }
    return 0;
}