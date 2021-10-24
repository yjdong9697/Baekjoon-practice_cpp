#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n_a, n_b;
    set<int> val_a;
    cin >> n_a >> n_b;

    for(int i = 0; i < n_a; i++){
        int t;
        cin >> t;
        val_a.insert(t);
    }

    for(int i = 0; i < n_b; i++){
        int t;
        cin >> t;
        if(val_a.find(t) != val_a.end()){
            val_a.erase(t);
        }
    }

    cout << val_a.size() << "\n";
    for(auto it = val_a.begin(); it != val_a.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}