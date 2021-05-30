#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int test_case;
    cin >> test_case;

    for(int i = 0; i < test_case; i++){
        int n;
        cin >> n;
    
        priority_queue<int, vector<int>, less<int> > l;
        priority_queue<int, vector<int>, greater<int> > r;

        vector<int> p_store;

        // First input
        int temp;
        cin >> temp;
        l.push(temp);
        p_store.push_back(temp);

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
                if(i % 2 == 1) p_store.push_back(l.top());
            }
            else if(l.size() > (i / 2) + (i % 2)){
                r.push(l.top());
                l.pop();
                if(i % 2 == 1) p_store.push_back(l.top());
            } 
            else{
                l.push(r.top());
                r.pop();
                if(i % 2 == 1) p_store.push_back(l.top());
            }
        }

        cout << p_store.size() << "\n";
        for(int i = 0; i< p_store.size(); i++){
            cout << p_store[i] << " ";
            if((i + 1) % 10 == 0 || i == p_store.size() - 1) cout << "\n";
        }
    } 
    return 0;
}