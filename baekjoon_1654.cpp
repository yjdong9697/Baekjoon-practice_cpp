#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int k, n;
    cin >> k >> n;
    int value_store[k];
    for (int i = 0; i < k; i++){
        cin >> value_store[i];
    }

    int max_value = * max_element(value_store, value_store + k);

    long long start = 1;
    long long end = max_value;

    while (end - start > 1){
        int mid = (start + end) / 2;
        long long sum = 0;
        
        for (int i = 0; i < k; i++){
            sum += value_store[i] / mid;
        }
        
        if (sum >= n){
            start = mid;
        }
        else end = mid - 1;
    }

    long long final_check = 0;

    for(int i = 0; i < k; i++){
        final_check += value_store[i] / end;
    }

    if (final_check >= n) cout << end << "\n";
    else cout << start << "\n";

    return 0;
}