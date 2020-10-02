#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int h, w, n;
        cin >> h >> w >> n;

        int element1 = n / h;
        int element2 = n % h;

        if(element2 == 0){
            if(element1 > 9){
                cout << h << element1 << "\n";
            }
            else{
                cout << h << "0" << element1 << "\n";
            }
        }

        else{
            if(element1 > 8){
                cout << element2 << element1 + 1 << "\n";
            }
            else{
                cout << element2 << 0 << element1 + 1 << "\n"; 
            }
        }
    }

    return 0;
}