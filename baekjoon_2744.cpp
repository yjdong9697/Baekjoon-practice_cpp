#include <bits/stdc++.h>
using namespace std;

int main(void){
    string t;
    cin >> t;
    for(int i = 0; i < t.size(); i++){
        if(t[i] >= 'a'){
            t[i] = t[i] - 'a' + 'A';
            
        }
        else{
            t[i] = t[i] - 'A' + 'a';
        }
    }
    cout << t << "\n";
}