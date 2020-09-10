#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    int data_store[n];

    for(int i = 0; i < n; i++){
        cin >> data_store[i];
    }

    sort(data_store, data_store + n);

    cout << data_store[0] << "\n";

    for(int i = 1; i < n; i++){
        if(data_store[i - 1] == data_store[i]) continue;
        
        else{
            cout << data_store[i] <<"\n";
        }
    }

    return 0;
}