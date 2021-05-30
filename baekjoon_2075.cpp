#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            if(pq.size() < n) pq.push(temp);
            else{
                if(pq.top() < temp){
                    pq.pop();
                    pq.push(temp);
                }
            }
        }
    }

    cout << pq.top() << "\n";
    return 0;
}