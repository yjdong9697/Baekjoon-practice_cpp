#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n; // Region num count

    vector<int> money_request;
    int sum = 0;
    for(int i = 0 ; i < n; i++){
        int temp;
        cin >> temp;
        money_request.push_back(temp);
        sum += temp;
    } // Store money request

    sort(money_request.begin(), money_request.end());

    int m;
    cin >> m;

    if(sum <= m){
        cout << money_request[n - 1] << "\n";
    }
    else{
        int start = 0;
        int end = money_request[n - 1];
        int mid;
        int result;
        while(start != end){
            mid = (start + end) / 2;
            long long sum = 0;
            for(int i = 0; i < n; i++){
                if(money_request[i] > mid){
                    sum += mid;
                }
                else{
                    sum += money_request[i];
                }
            }
            if(sum <= m){
                result = mid;
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        cout << result << "\n";

    }
    
    return 0;
}