#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    string o;

    for(int i = 0; i < n; i++){
        if(s[i] == 'J' || s[i] == 'A' || s[i] == 'V'){
            continue;
        }
        else{
            o += s[i];
        }
    }

    if(o.size() == 0){
        cout << "nojava\n";
    }
    else{
        cout << o << "\n";
    }

    return 0;
}