#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;

    int temp1 = 2;
    int temp2 = 5;

    int check_2 = 0;
    int check_5 = 0;

    while (temp1 <= n){
        check_2 += n / temp1;
        temp1 *= 2;
    }
    
    while (temp2 <= n){
        check_5 += n / temp2;
        temp2 *= 5;
    }

    cout << min(check_2, check_5) << "\n";
    return 0;

}