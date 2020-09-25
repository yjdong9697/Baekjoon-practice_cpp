#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const int a, const int b){
    return a > b;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> data_store;

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }

    sort(data_store.begin(), data_store.end(), compare);

    for(int i = 0; i < n; i++){
        cout << data_store[i] << "\n";
    }
}