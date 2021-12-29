#include <bits/stdc++.h>
#define fastio ios_Baes::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    string a;
    cin >> a;
    if(a.size() == 2){
        int v1 = a[0] - '0';
        int v2 = a[1] - '0';
        cout << v1 + v2 << "\n";
    }
    else if(a.size() == 3){
        int v1;
        int v2;

        if(a[1] == '0'){
            v1 = stoi(a.substr(0, 2));
            v2 = a[2] - '0';
        }
        else{
            v1 = a[0] - '0';
            v2 = stoi(a.substr(1, 3));
        }
        cout << v1 + v2 << "\n";
    }
    else{
        int v1;
        int v2;
        v1 = stoi(a.substr(1, 3));
        v2 = stoi(a.substr(2, 4));
        cout << v1 + v2 << "\n";
    }
    return 0;
}