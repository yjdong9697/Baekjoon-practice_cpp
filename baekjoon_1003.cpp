#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct{
    int zero;
    int one;
}fib_num;

fib_num fib(int n, vector<fib_num> & fib_store);

int main(void){
    int T;
    cin >> T;

    vector<fib_num> fib_store;
    
    fib_num zero_case;
    zero_case.zero = 1;
    zero_case.one = 0;
    fib_store.push_back(zero_case);

    fib_num one_case;
    one_case.zero = 0;
    one_case.one = 1;
    fib_store.push_back(one_case);

    for (int i = 0; i < T; i++){
        int test_case;
        cin >> test_case;
        fib_num result = fib(test_case, fib_store);
        cout << result.zero << " " << result.one << "\n";
    }

    return 0;
}

fib_num fib(int n, vector<fib_num> & fib_store){
    if (n == 1 || n == 0) return fib_store[n]; //early exit

    if (fib_store.size() > n) return fib_store[n];

    else if(fib_store.size() < n){
        fib(n - 1, fib_store);
    }
    fib_num temp;
    temp.one = fib_store[n - 1].one + fib_store[n - 2].one;
    temp.zero = fib_store[n - 1].zero + fib_store[n - 2].zero;
    fib_store.push_back(temp);
    
    return temp;
}