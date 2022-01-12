#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
double INF = 2000.0;
double distance(pdd& v1, pdd& v2){
    return sqrt(pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2));
}

int main() {
    fastio;
    double s_x, s_y, e_x, e_y;
    cin >> s_x >> s_y >> e_x >> e_y;

    int n;
    cin >> n;
    vector<pdd> v;
    v.push_back({s_x, s_y});

    for(int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({e_x, e_y});

    double dist[102];
    fill(dist, dist + 102, INF);
    dist[0] = (double)0;
    priority_queue<pdi, vector<pdi>, greater<pdi> > pq;
    pq.push({0, 0});

    bool flag = true;

    while(!pq.empty()){
        double cur_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cur_cost) continue;
        for(int i = 0; i <= n + 1; i++){
            double length = distance(v[cur], v[i]);
            double walk_cost = length / 5;
            double shoot_cost = 2 + fabs(length - 50) / 5;
            double min_cost;
            if(flag){
                min_cost = walk_cost;
            }
            else{
                min_cost = min(walk_cost, shoot_cost);
            }
            if(cur_cost + min_cost < dist[i]){
                dist[i] = cur_cost + min_cost;
                pq.push({dist[i], i});
            }
        }
        flag = false;
    }

    cout << dist[n + 1] << "\n";
    return 0;
}