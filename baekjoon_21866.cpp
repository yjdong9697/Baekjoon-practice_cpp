#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int checker[9] = {100, 100, 200, 200, 300, 300, 400, 400, 500};
    bool input = false;
    int total = 0;

    for(int i = 0; i < 9; i++){
        int temp;
        cin >> temp;
        if(checker[i] < temp){
            cout << "hacker" << "\n";
            return 0;
        }
        else{
            total += temp;
        }
    }

    if(total >= 100){
        cout << "draw\n";
    }
    else{
        cout << "none\n";
    }

    return 0;




}