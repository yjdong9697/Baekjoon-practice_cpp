#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<long long> check_value;
    for(int i = 0; i < n; i++){
        long long input_data;
        cin >> input_data;
        check_value.push_back(input_data); 
    } // Input data

    sort(check_value.begin(), check_value.end());

    int m;
    cin >> m;

    for (int j = 0; j < m; j++){
        long long compare;
        cin >> compare;

        int start = 0;
        int end = n;
        int mid;

        //Binary search
        while(start != end){
            int mid = (start + end) / 2;

            if(check_value[mid] < compare){
                start = mid + 1;
            }
            else if(check_value[mid] >= compare){
                end = mid;
            }
        }
        cout << (check_value[start] == compare) << "\n";

    }

    return 0;
}