#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int n;
    map<string, int> set_value;
    cin >> n;

    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        // Not exist in set
        if(set_value.find(t) == set_value.end()){
            set_value[t] = 1;
        }
        else{
            set_value[t] += 1;
        }
    }

    int max_value = -1;
    string value;

    for(auto it = set_value.begin(); it != set_value.end(); it ++){
        if(it -> second > max_value){
            max_value = it -> second;
            value = it -> first;
        }
    }

    cout << value << "\n";

    return 0;
}