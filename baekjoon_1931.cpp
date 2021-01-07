#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int> > data_store;

    for(int i = 0; i < N; i++){
        int start_num, end_num;
        cin >> start_num >> end_num;
        data_store.push_back(make_pair(end_num, start_num));
    }// Data_store

    sort(data_store.begin(), data_store.end()); // Sorting data

    int end_point_store = 0;
    int result = 0;

    for(int i = 0; i < N; i++){
        if(data_store[i].second < end_point_store) continue;
        else{
            end_point_store = data_store[i].first;
            result += 1;
        }
    }

    cout << result << "\n";
    return 0;
}