#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdlib>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> data_store;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }

    sort(data_store.begin(),data_store.end());

    for(int i = 0; i < n; i++){
        cout << data_store[i] << "\n";
    }

    return 0;
}