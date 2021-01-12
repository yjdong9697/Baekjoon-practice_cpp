#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int passenger_num, passport_num;
vector<int> data_store;
int visited[101];

int main(void){
    cin >> passenger_num >> passport_num;
    fill_n(visited, 101, 0); // Initialize

    for(int i = 0; i < passenger_num; i++){
        int temp;
        cin >> temp;
        data_store.push_back(temp);
    }

    int count = 0;

    for(int i = 0; i < passenger_num; i++){
        if(visited[data_store[i]] == 1) continue; // Already visited
        else{
            visited[data_store[i]] == 1;
            int check_num = data_store[i];
            for(int j = i + 1; j < passenger_num; j++){
                if(check_num < data_store[j] && visited[data_store[j]] != 1){
                    check_num = data_store[j];
                    visited[data_store[j]] = 1; // Visited processing
                }
            }
            count += 1;
        }
    }

    if(count <= passport_num){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}