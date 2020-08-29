#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int factorial(int, int *);

int main(void){
    int n;
    cin >> n;
    int factorial_memorial[14] = {1,1};
    int *fac_point = factorial_memorial;

    cout << factorial(n, fac_point) << "\n" ;

    return 0;
}

int factorial(int n, int *fac_point){
    
    if (n <= 1) return 1;

    else{
        factorial(n - 1, fac_point);
        int value = n * (fac_point[n - 1]);
        fac_point[n] = value;
        return value;
    }
}