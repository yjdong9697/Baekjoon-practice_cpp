#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n, m;
    cin >> n >> m;
    map<string, int> set_1;
    map<int, string> set_2;

    for(int i = 1; i <= n; i++){
        string p;
        cin >> p;
        set_1[p] = i;
        set_2[i] = p;
    }

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if('A' <= s[0] && s[0] <= 'Z'){
            cout << set_1[s] << "\n";
        }
        else{
            cout << set_2[stoi(s)] << "\n";
        }
    }
    return 0;
}