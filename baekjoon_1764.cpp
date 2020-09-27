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
    int n, m;
    cin >> n >> m;

    set<string> data_store;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        data_store.insert(temp);
    }

    int count = 0;
    vector<string> result_store;
    vector<string>::iterator it;

    for(int i = 0; i < m; i++){
        string test_case;
        cin >> test_case;
        
        if(data_store.count(test_case) == 1){
            count += 1;
            result_store.push_back(test_case);
        }
    }
    sort(result_store.begin(), result_store.end());

    cout << count << "\n";
    for(it = result_store.begin(); it != result_store.end(); it++){
        cout << *it << "\n";
    }
}