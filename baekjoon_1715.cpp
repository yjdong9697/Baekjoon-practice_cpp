#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int result = 0;

    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        result += (first + second);
        pq.push(first + second);
    }

    cout << result << "\n";
    return 0;
}