#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector <int> store;

    for(int i = 0; i < n; i++){
        string check;
        cin >> check;

        if (check == "push"){
            int temp;
            cin >> temp;

            store.push_back(temp); // push data
        }

        else if(check == "pop"){
            if (store.size() == 0){
                cout << "-1\n";
                continue;
            }
            cout << store[store.size() - 1] << "\n";
            store.pop_back();
        }

        else if(check == "size"){
            cout << store.size() << "\n";
        }
        
        else if(check == "empty"){
            if (store.size() == 0){
                cout << "1\n";
                continue;
            }
            else cout << "0\n";
        }

        else if(check == "top"){
            if (store.size() == 0){
                cout << "-1\n";
                continue;
            }
            cout << store[store.size() - 1] << "\n";
        }
    }

    return 0;
}