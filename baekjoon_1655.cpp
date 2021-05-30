#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, less<int> > l;
    priority_queue<int, vector<int>, greater<int> > r;

    // First input
    int temp;
    cin >> temp;
    l.push(temp);
    cout << temp << "\n";

    for(int i = 2; i <= n; i++){
        int t;
        cin >> t;

        // 일단 왼쪽보다 작거나 같으면 왼쪽에다가 넣음
        if(l.top() >= t){
            l.push(t);
        }
        else{
            r.push(t);
        }

        // 빼고 정리하는 작업
        if(l.size() == (i / 2) + (i % 2)){
                cout << l.top() << "\n";
        }
        else if(l.size() > (i / 2) + (i % 2)){
            r.push(l.top());
            l.pop();
            cout << l.top() << "\n";
        }
        else{
            l.push(r.top());
            r.pop();
            cout << l.top() << "\n";
        }
    }
}