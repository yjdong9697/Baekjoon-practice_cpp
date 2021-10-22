#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;

    map<string, int> set_value;
    vector<string> v;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        set_value[s] = i;
    }

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    int result = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(set_value[v[i]] > set_value[v[j]]){
                result++;
                break;
            }
        }
    }
    cout << result << "\n";
    return 0;
}