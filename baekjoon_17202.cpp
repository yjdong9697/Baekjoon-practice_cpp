#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    string a, b;
    cin >> a >> b;
    queue<int> q;

    for(int i = 0; i < 8; i++){
        q.push(a[i] - '0');
        q.push(b[i] - '0');
    }

    int recur = 15;

    while(q.size() != 2){
        for(int i = 0; i < recur; i++){
            int t = q.front();
            q.pop();
            q.push((t + q.front()) % 10);
        }
        q.pop();
        recur--;
    }

    cout << q.front() << q.back() << "\n";
    return 0;
}