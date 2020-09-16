#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> data_store(10001, 0);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        data_store[temp] += 1;
    }

    for(int i = 1; i < 10001; i++){
        for(int j = 0; j < data_store[i]; j++){
            cout << i << "\n";
        }
    }

    return 0;
}