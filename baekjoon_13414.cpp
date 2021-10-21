#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int k, l;
    map<string, int> s_1;
    map<int, string> s_2;
    cin >> k >> l;

    for(int i = 1; i <= l; i++){
        string v;
        cin >> v;
        if(s_1.find(v) != s_1.end()) s_2.erase(s_1[v]);
        s_1[v] = i;
        s_2[i] = v;
    }
    int count = 1;

    for(map<int,string>::iterator it = s_2.begin(); it != s_2.end(); it++){
        cout << it -> second << "\n";
        if(count == k) break;
        else count++;
    }
    return 0;
}