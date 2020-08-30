#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    while(true){
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0){
            return 0;
        }
        else{
            cout << a + b << "\n";
        }

    }
    
    return 0;
}