#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    vector<int> data_store;
    int current_length = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
        current_length += temp;
    }
    sort(data_store.begin(), data_store.end());

    long long result = 0;

    for(int i = 0; i< n; i++){
        result += data_store[i] * (current_length - data_store[i]);
        current_length -= data_store[i];
    }
    cout << result << "\n";
    return 0;
}