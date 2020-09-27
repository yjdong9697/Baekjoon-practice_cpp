#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    for(int t = 0; t < test_case; t++){
        int n;
        cin >> n;
        vector<int> data_store;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            data_store.push_back(temp);
        }
        sort(data_store.begin(),data_store.end());
    
        int m;
        cin >> m;

        for(int i = 0; i < m; i++){
            int test_num;
            cin>> test_num;
            int start = 0;
            int end = n;
            while(start != end){
                int mid = (start + end) / 2;

                if(data_store[mid] < test_num){
                    start = mid + 1;
                }
                else{
                    end = mid;
                }
            }
            if(data_store[start] == test_num){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }

    }
    return 0;
}