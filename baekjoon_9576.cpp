#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

struct compare{
    bool operator()(const pii &value1, const pii &value2){
        return value1.second> value2.second;
    }
};

int main(void){
    fastio;
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        int n, m;
        cin >> n >> m;
        for(int j = 0; j < m; j++){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            pq.push(make_pair(temp1, temp2));
        }
        priority_queue<pii, vector<pii>, compare> check_pq;
        int result = 0;
        for(int j = 1; j <= n; j++){
            while(!pq.empty()){
                pii check = pq.top(); pq.pop();
                if(check.first <= j && j <= check.second){
                    check_pq.push(check);
                }
                else{
                    pq.push(check);
                    break;
                }
            }
            while(!check_pq.empty()){
                pii booked = check_pq.top(); check_pq.pop();
                if(j <= booked.second){
                    result += 1;
                    break;
                }
            }
        }
        cout << result << "\n";
    }

    return 0;
}