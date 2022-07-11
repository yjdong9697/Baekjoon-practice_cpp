#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main() {
    fastio;
    int n;
    cin >> n;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    priority_queue<int, vector<int>, greater<int> > pq_end;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({b, c});
    }

    while(!pq.empty()){
        int cur_s, cur_e;
        tie(cur_s, cur_e) = pq.top();
        pq.pop();
        if(pq_end.empty()) pq_end.push(cur_e);
        else{
            int cmp = pq_end.top();
            if(cmp > cur_s) pq_end.push(cur_e);
            else{
                pq_end.pop();
                pq_end.push(cur_e);
            }
        }
    }

    cout << pq_end.size() << "\n";
    return 0;
}