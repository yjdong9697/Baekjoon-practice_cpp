#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > pq; // // Min heap

    for(int i = 0 ; i < n; i++){
        int temp;
        cin >> temp;

        if(temp != 0){
            pq.push(temp);
        }
   
        else{
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }     
        }
    }

    return 0;

}