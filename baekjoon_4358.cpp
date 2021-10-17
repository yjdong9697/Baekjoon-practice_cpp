#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int total = 0;
    string t;
    map<string, int> set_value;
    
    while(getline(cin, t)){
        if(set_value.find(t) == set_value.end()){
            set_value[t] = 1;
        }
        else set_value[t] += 1;
        total++;
    }

    for(map<string,int>::iterator it = set_value.begin(); it != set_value.end(); it++){
        cout << fixed;
        cout.precision(4);
        cout << it -> first << " " << (float) (it -> second * 100) / total  << "\n";
    }
    return 0;
}