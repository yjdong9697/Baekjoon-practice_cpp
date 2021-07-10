#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef pair<int, int> pii;

int main(void){
    fastio;
    int n;
    deque<int> d;
    deque<int> index;
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        d.push_back(t);
        index.push_back(i);
    }

    for(int i = 0; i < n; i++){
        int v = d.front();
        cout << index.front() << " ";
        d.pop_front();
        index.pop_front();
        

        if(v > 0){
            for(int i = 0; i < v - 1; i++){
                d.push_back(d.front());
                d.pop_front();
                index.push_back(index.front());
                index.pop_front();
            }
        }
        else{
            for(int i = v; i < 0; i++){
                d.push_front(d.back());
                d.pop_back();
                index.push_front(index.back());
                index.pop_back();
            }
        }
    }

    cout << "\n";
    return 0;
}