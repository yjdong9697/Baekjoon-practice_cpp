#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    while(true){
        int a, b;
        cin >> a >> b;

        if (cin.eof()) break;
        cout << a + b << "\n";

    }

    return 0;
}