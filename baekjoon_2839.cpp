#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int max = n / 5;
    int result;
    for(int i = max; i >= 0; i--){
        if((n - (i * 5)) % 3 == 0){
            cout << ((n - (i * 5)) / 3) + i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}