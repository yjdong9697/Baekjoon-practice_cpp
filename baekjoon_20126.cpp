#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, m, s;
    cin >> n >> m >> s;

    vector<pair<int, int> > data_store;
    for(int i= 0; i < n; i++){
        int start_clock_temp, using_time;
        cin >> start_clock_temp >> using_time;
        data_store.push_back(make_pair(start_clock_temp, using_time));
    }

    sort(data_store.begin(), data_store.end()); 

    if(data_store[0].first >= m){
        cout << "0\n"; // 처음 시작할때 가능한 경우 따로 체크
        return 0;
    }
    else{
        for(int i = 0; i < n - 1; i++){
            if(data_store[i + 1].first - (data_store[i].first + data_store[i].second) >= m){
                cout << data_store[i].first + data_store[i].second << "\n";
                return 0;
            }
        }
        if((s - (data_store[n - 1].first + data_store[n - 1].second)) >= m){
            cout << data_store[n - 1].first + data_store[n - 1].second << "\n";
            return 0;
        }
        else{
            cout << "-1\n";
            return 0;
        }
    }
}