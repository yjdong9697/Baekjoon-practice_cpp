#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    //교집합의 개수만 지워주면 된다.
    int a, b;
    int int_num = 0;
    cin >> a >> b;

    set<int> set_value;
    for(int i = 0; i < a; i++){
        int t;
        cin >> t;
        set_value.insert(t);
    }


    for(int i = 0; i < b; i++){
        int t;
        cin >> t;
        if(set_value.find(t) != set_value.end()) int_num++;
    }
    cout << a + b - 2 * int_num << "\n";
    return 0;
}