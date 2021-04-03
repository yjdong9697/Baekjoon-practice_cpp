#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;

    stack<bool> data;

    for(int i = 0; i < n; i++){
        string check;
        cin >> check;
        bool value = (check == "TRUTH") ? true : false;
        data.push(value);
    }

    bool current_status = true;

    while(!data.empty()){
        bool cur = data.top(); data.pop();
        if(current_status){
            current_status = cur;
        }
        else{
            current_status = !cur;
        }
    }

    if(current_status){
        cout << "TRUTH\n";
    }
    else cout << "LIE\n";
    
    return 0;
}