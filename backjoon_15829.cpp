#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    
    string data;
    cin >> data;

    int r = 31;
    int M = 1234567891;

    ll hash = 0; 

    for(int i = 0; i < n; i++){
        int temp = data[i] - 'a' + 1;
        ll save = temp;
        for(int j = 1 ; j <= i; j++){
            save *= r;
            save %= M;
        }
        hash += save;
    }

    cout << hash % M << "\n";
    return 0;
}