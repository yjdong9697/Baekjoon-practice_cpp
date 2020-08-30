#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int fib(int n, int *);

int main(void){
    int n;
    cin >> n;

    int fib_store[21] = {0, 1};
    int * fib_point = fib_store;

    fib(n, fib_point);
    cout << fib_store[n] << "\n";

    return 0;

}

int fib(int n, int * fib_point){
    if (n > 1) {
        if (fib_point[n] == 0){
            fib(n - 1, fib_point);
            fib_point[n] = fib_point[n - 1] + fib_point[n - 2];
        }
        return 0;
    }
    else{
        return 0;
    }
}