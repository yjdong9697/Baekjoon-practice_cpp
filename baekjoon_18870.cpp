#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<long long> data;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        data.push_back(value);
    }

    vector<long long> data_save = data;
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    
    int size_of_data = data.size();

    for(int i = 0; i<n; i++){
        int start = 0;
        int end = size_of_data;
        int mid = (start + end) / 2;

        // Binary search
        while(true){
            mid = (start + end) / 2;
            if (data[mid] > data_save[i]){
                end = mid - 1;
            }
            else if(data[mid] < data_save[i]){
                start = mid + 1;
            }
            else break;
        }
        cout << mid << " ";
    }
    
    cout << "\n";

    return 0;
}