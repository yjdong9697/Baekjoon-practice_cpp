#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n, query;
    cin >> n >> query;
    vector<int> data;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data.push_back(temp);
    }

    sort(data.begin(), data.end());

    int start = 0;
    int end = 1000000001;

    while(start < end){
        int mid = (start + end) / 2;
        int prev = data[0];
        int query_num = 0;
        for(int i = 1; i < data.size(); i++){
            if(data[i] - prev >= mid){
                prev = data[i];
                query_num++;
            }
        }

        if(query_num >= query - 1){
            start = mid + 1;
        }
        else end = mid;
    }

    cout << start - 1 << "\n";
    return 0;
}