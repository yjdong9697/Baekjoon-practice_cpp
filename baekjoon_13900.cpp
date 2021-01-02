#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> sum_store;
    for(int i = 0 ; i < n; i ++){
        int temp;
        cin >> temp;
        sum_store.push_back(temp);
    }

    long long sum_value = 0;
    for(int i = 0; i < sum_store.size(); i++){
        sum_value += sum_store[i];
    }

    long long result = 0;

    for(int i = 0; i < sum_store.size(); i++){
        result += (sum_value - sum_store[i]) * sum_store[i];
    }

    cout << result / 2 << "\n";

    return 0;
}