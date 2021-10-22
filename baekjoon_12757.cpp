#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n, m, k;
map<int, int> s;

int find_key(int t){ 
    if(s.lower_bound(t) == s.begin()){
        if(s.lower_bound(t) -> first - t <= k){
            return s.lower_bound(t) -> first;
        }
        else return -1;
    }
    else if(s.lower_bound(t) == s.end()){
        if(t - (--s.lower_bound(t)) -> first <= k){
            return (--s.lower_bound(t)) -> first;
        }
        else return -1;
    }
    else{
        int prev_dif = t - (--s.lower_bound(t)) -> first;
        int next_dif = s.lower_bound(t) -> first - t;
        
        if(prev_dif == next_dif){
            return -2;
        }
        
        else if(prev_dif < next_dif){
            if(prev_dif <= k) return (--s.lower_bound(t)) -> first;
            else return -1;
                
        }
        else{
            if(next_dif <= k) return s.lower_bound(t) -> first;
            else return -1;       
        } 
    }
}

int main(void){
    fastio;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        s[a] = b;
    }

    for(int i = 0; i < m; i++){
        int check;
        cin >> check;
        if(check == 1){
            int a, b;
            cin >> a >> b;
            s[a] = b;
        }
        else if(check == 2){
            int a, b;
            cin >> a >> b;
            int val = find_key(a);
            if(a == -2 || a == -1) continue;
            else{
                s.erase(val);
                s[val] = b;
            }
        }
        else{
            int a;
            cin >> a;
            int val = find_key(a);
            if(val == -1) cout << "-1\n";
            else if(val == -2) cout << "?\n";
            else{
                cout << s[val] << "\n";
            }
        }
    }
    return 0;
}