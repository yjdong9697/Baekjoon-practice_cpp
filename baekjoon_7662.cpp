#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int k;
        multiset<int> s;
        cin >> k;
        for(int i = 0; i < k; i++){
            char l;
            int n;
            cin >> l >> n;
            if(l == 'D'){
                if(s.empty()) continue; // Exception handling
                if(n == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
            else s.insert(n);
        }
             
        if(s.empty()){
            cout << "EMPTY\n";
        }
        else{
            cout << *(--s.end()) << " " << *s.begin() << "\n";
        }
    }
    return 0;
}