#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n, count = 1;
    cin >> n;

    if (n == 1){
        cout << "666\n";
        return 0;
    }
    
    int num = 1000;

    while(count < n){
        int stack = 0;
        int temp = num;

        while(temp >= 1){

            if (temp % 10 == 6){
                stack += 1;

                if (stack >= 3){
                    count += 1;
                    break;
                } 

            }

            else stack = 0;

            temp /= 10;

        }

        if (count != n) num += 1;

    }

    cout << num << "\n";

    return 0;

}