#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> >pq;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(i % 2 == 0){
            pq.push(temp);
            vector<int> junk_store;
            for(int j = 0; j < (i / 2); j++){
                junk_store.push_back(pq.top());
                pq.pop();
            }
            cout << pq.top() << "\n";
            for(int i = 0; i < junk_store.size(); i++){
                pq.push(junk_store[i]);
            }
        }
        else if(i % 2 == 1){
            pq.push(temp);
            vector<int> junk_store;
            for(int j = 0; j < (i / 2); j++){
                junk_store.push_back(pq.top());
                pq.pop();
            }
            int check1 = pq.top();
            pq.pop();
            int check2 = pq.top();
            cout << min(check1, check2) << "\n";
            for(int i = 0; i < junk_store.size(); i++){
                pq.push(junk_store[i]);
            }
            pq.push(check1);
            pq.push(check2);

        }
    }

    return 0;
}