#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>


using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<pair<int, int> > cor_store;
    for(int i = 0; i < n; i++){
        pair<int, int> temp;
        cin >> temp.first >> temp.second;

        cor_store.push_back(temp);
    }

    sort(cor_store.begin(),cor_store.end()); // sorting data

    for(int i = 0; i < n; i++){
        cout << cor_store[i].first << " " << cor_store[i].second << "\n";
    }

    return 0;
}