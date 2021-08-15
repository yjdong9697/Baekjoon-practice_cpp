#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int temp = n;
    int count = 0;

    int first = n / 10;
    int second = n % 10;
    int sum = (first + second) % 10;

    n = second * 10 + sum;

    count += 1; // first cycle

    while (n != temp){
        int first = n / 10;
        int second = n % 10;
        int sum = (first + second) % 10;

        n = second * 10 + sum;
        count += 1;
    }

    cout << count << "\n";

    return 0;

}