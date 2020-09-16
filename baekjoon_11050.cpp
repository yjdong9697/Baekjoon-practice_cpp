#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    int result_above = 1;

    for(int i = 0; i < k; i++){
        result_above *= (n - i);
    }

    int result_down = 1;

    for(int i = 1; i < k + 1; i ++){
        result_down *= i;
    }

    cout << result_above / result_down << "\n";

    return 0;
}