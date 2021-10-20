#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    set<string> s;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string name, value;
        cin >> name >> value;
        if(value == "enter"){
            s.insert(name);
        }
        else{
            s.erase(name);
        }
    }

    for(set<string>::reverse_iterator  it = s.rbegin(); it != s.rend(); it++){
        cout << *it << "\n";
    }
    return 0;
}