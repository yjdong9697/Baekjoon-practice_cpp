#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> tree_length_store;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        tree_length_store.push_back(temp);
    }
    sort(tree_length_store.begin(), tree_length_store.end());
    int start = 0;
    int end = tree_length_store[n - 1];
    int mid;
    int result;

    while(start != end){
        mid = (start + end) / 2;
        long long compare_value = 0;
        for(int i = 0; i < n; i++){
            if(tree_length_store[i] > mid){
                compare_value += tree_length_store[i] - mid;
            }
        }
        if(compare_value >= m){
            result = mid;
            start = mid + 1;
        }
        else end = mid;
    }

    cout << result << "\n";
    return 0;

}