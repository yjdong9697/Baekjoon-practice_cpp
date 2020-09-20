#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> queue_store;
    int start = 0;

    for(int i = 0; i < n; i++){
        string what_type;
        cin >> what_type;
        
    
        if(what_type == "push"){
            int temp;
            cin >> temp;

            queue_store.push_back(temp); // push data;
        }
        else if(what_type == "pop"){
            if(queue_store.size() - start == 0){
                cout << "-1\n";
            }
            else{
                cout << queue_store[start] << "\n";
                start += 1;
            }

        }
        else if(what_type == "size"){
            cout << queue_store.size() - start << "\n";

        }
        else if(what_type == "empty"){
            if(queue_store.size() - start == 0){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }

        }
        else if(what_type == "front"){
            if(queue_store.size() - start == 0){
                cout << "-1\n";
            }
            else{
                cout << queue_store[start] << "\n";
            }

        }
        else if(what_type == "back"){
            if(queue_store.size() - start == 0){
                cout << "-1\n";
            }
            else{
                int back_num;
                back_num = queue_store.size() - start;
                cout << queue_store[start + back_num - 1] << "\n";
            }

        }
    }

    return 0;
}