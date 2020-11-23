#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    vector<pair<int, int> > path_store;
};

int checker(node *data_store, int start, int len){
    int sum = len;

    int length = data_store[start].path_store.size();
    int max = 0;
    for(int i = 0 ; i < length; i++){
        if(max < checker(data_store, data_store[start].path_store[i].first, data_store[start].path_store[i].second)){
            max = checker(data_store, data_store[start].path_store[i].first, data_store[start].path_store[i].second);
        }
    }
    sum += max;

    return sum;
}

int main(void){
    int n;
    cin >> n;

    node data_store[n + 1];

    for(int i = 0; i < n - 1; i++){
        int parent, child, length;
        cin >> parent >> child >> length;
        data_store[parent].path_store.push_back(make_pair(child, length));
    }// data_store

    int max = 0;

    for(int i = 1; i < n + 1; i++){
        int data_size = data_store[i].path_store.size();
        vector<int> sum_store(10001,0);
        for(int j = 0; j < data_size; j++){
            sum_store[j] = checker(data_store, data_store[i].path_store[j].first, data_store[i].path_store[j].second);

        }
        sort(sum_store.begin(), sum_store.end(), greater<int>());
        if(max < sum_store[0] +sum_store[1] ) max = sum_store[0] +sum_store[1];
    }

    cout << max << "\n";

    return 0;
}