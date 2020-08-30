#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    long long n;
    cin >> n;

    if (n % 2 == 0){
        cout << "CY\n";
    }

    else{
        cout << "SK\n";
    }


    return 0;
}