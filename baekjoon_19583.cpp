#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    string s, e, q;
    cin >> s >> e >> q;
    set<string> interance;
    set<string> accepted;

    while(true){
        string a, b;
        cin >> a >> b;
        if(a == "" && b == "") break;
        if(a <= s){
            interance.insert(b);
            continue;
        }
        if(e <= a && a <= q){
            if(interance.find(b) != interance.end()){
                accepted.insert(b);
                continue;
            }
        }
    }

    cout << accepted.size() << "\n";
    return 0;
}