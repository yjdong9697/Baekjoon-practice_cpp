#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;

    set<string> s;

    for(int i = 0; i < n; i++){
        string v;
        cin >> v;
        s.insert(v);
    }

    for(int i = 0; i < n - 1; i++){
        string v;
        cin >> v;
        s.erase(v);
    }

    cout << *s.begin() << "\n";
    return 0;
}