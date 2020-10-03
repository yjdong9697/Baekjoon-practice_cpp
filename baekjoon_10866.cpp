#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int n;
    cin >> n;
    deque<int> data_store;
    
    for(int i = 0; i < n; i++){
        string checker;
        cin >> checker;

        if(checker == "push_front"){
            int temp;
            cin >> temp;
            data_store.push_front(temp);


        }
        else if(checker == "push_back"){
            int temp;
            cin >> temp;
            data_store.push_back(temp);

        }
        else if(checker == "pop_front"){
            if(data_store.empty() == 1){
                cout << "-1\n";
            }
            else{
                cout << data_store.front() << "\n";
                data_store.pop_front();
            }
        }
        else if(checker == "pop_back"){
            if(data_store.empty() == 1){
                cout << "-1\n";
            }
            else{
                cout << data_store.back() << "\n";
                data_store.pop_back();
            }

        }
        else if(checker == "size"){
            cout << data_store.size() << "\n";

        }
        else if(checker == "empty"){
            cout << data_store.empty() << "\n";

        }
        else if(checker == "front"){
            if(data_store.empty() == 1){
                cout << "-1\n";
            }
            else{
                cout << data_store.front() << "\n";
            }
        }
        else if(checker == "back"){
            if(data_store.empty() == 1){
                cout << "-1\n";
            }
            else{
                cout << data_store.back() << "\n";
            }
        }
    }

    return 0;

}