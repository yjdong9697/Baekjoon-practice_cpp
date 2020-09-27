#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map<long long, int> map_data;
    map<long long, int>::iterator it;

    for(int i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        if (map_data.count(temp) != 0){
            map_data[temp] += 1;
        }
        else{
            map_data[temp] = 1;
        }
    }

    long long max_check = -1;
    long long result_temp = -10e24;

    for(it = map_data.begin(); it != map_data.end(); it++){
        if (it ->second > max_check){
            max_check = it ->second;
            result_temp = it ->first;
        }
        else if(it ->second == max_check){
            if(it ->first < result_temp){
                result_temp = it ->first;
            }
        }    
    }

    cout << result_temp << "\n";
    return 0;
}