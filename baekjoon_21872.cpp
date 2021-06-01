#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int t;
    cin >> t;
    int k, l;
    cin >> k >> l;
    for(int i = 0; i < t; i++){
        int n_1;
        cin >> n_1;

        string value_1;
        cin >> value_1;

        int n_2;
        cin >> n_2;

        string value_2;
        cin >> value_2;

        if(k ==1){ cout << "YS\n";}
        else{
            if(n_1 > n_2){
                cout << "S\n";
            }
            else if(n_1 < n_2){
                cout << "Y\n";
            }
            else cout << "YS\n";
        }
    }
    return 0;
}