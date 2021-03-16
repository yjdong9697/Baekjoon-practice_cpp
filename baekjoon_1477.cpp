#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> data;
    vector<int> length;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data.push_back(temp);
    }

    sort(data.begin(), data.end());

    length.push_back(data[0]);

    for(int i = 1; i < data.size(); i++){
        length.push_back(data[i] - data[i - 1]);
    }

    length.push_back(l - data[data.size() - 1]);

    sort(length.begin(), length.end());

    int start = length[0];
    int end = length[length.size() - 1];

    while(start < end){
        int mid = (start + end) / 2;
        int count_store = 0;

        for(int i = 0; i < length.size(); i++){
            if(length[i] % mid == 0){
                count_store += length[i] / mid - 1;
            }
            else count_store += (length[i] / mid);
        }

        if(count_store > m){
            start = mid + 1;
        }
        else end = mid;
    }

    cout << start << "\n";
    return 0;
}