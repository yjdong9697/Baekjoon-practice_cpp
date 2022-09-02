#include <bits/stdc++.h>
using namespace std;

int main(void){
    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        int diff = 10000000;
        int val = -1;
        for(int i = 1; i <= 1000001; i++){
            int tmp = 1;
            for(int j = 0; j < b; j++) tmp *= i;
            if(abs(tmp - a) < diff){
                diff = abs(tmp - a);
                val = i;
            }
            else{
                break;
            }   
        }
        cout << val << "\n";
    }
    return 0;
}