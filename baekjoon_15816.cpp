#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000001

using namespace std;
int seg[12000008];
int req[1000002][2];
vector<int> s;

void update(int node_index, int node_left, int node_right, int update_index){
    if(update_index < node_left || update_index > node_right) return; // Out of bound
    
    // Base case
    if(node_left == node_right){
        seg[node_index]++;;
        return;
    }
    else{
        int mid = (node_left + node_right) / 2;
        update(node_index * 2, node_left, mid, update_index);
        update(node_index * 2 + 1, mid + 1, node_right, update_index);
        seg[node_index]++;
    }
}

int query(int node_index, int node_left, int node_right, int query_left, int query_right){
    // Out of bound
    if(query_right < node_left || node_right < query_left) return 0;
    // All satisfied
    else if(query_left <= node_left && query_right >= node_right) return seg[node_index];

    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right) +
           query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
}

int lower_bound_index(int num){
    return lower_bound(s.begin(), s.end(), num) - s.begin();
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));
    memset(req, 0, sizeof(req));
    
    int N, M;
    vector<int> input_value;
    
    // Input data 
    cin >> N;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        s.push_back(t);
        input_value.push_back(t);
    }

    // Request
    cin >> M;
    for(int i = 0; i < M; i++){
        int q;
        cin >> q;
        // Update seg
        if(q == 1){
            int u;
            cin >> u;
            s.push_back(u);
            req[i][0] = u;
            req[i][1] = INF;
        }
        // Request current query value (Storing query)
        else{
            int v1, v2;
            cin >> v1 >> v2;
            s.push_back(v1);
            s.push_back(v2);
            req[i][0] = v1;
            req[i][1] = v2;
        }
    }

    s.push_back(-INF); // 강제로 시작 index를 1로 만들어줌
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end()); // 겹치는거 지워줌

    int node_left = 1;
    int node_right = s.size() - 1;

    for(int i = 0; i < input_value.size(); i++){
        update(1, node_left, node_right, lower_bound_index(input_value[i]));
    }

    for(int i = 0; i < M; i++){
        // Request : 1
        if(req[i][1] == INF){
            update(1, node_left, node_right, lower_bound_index(req[i][0]));
        }
        else{
            int p_sum = query(1, node_left, node_right, lower_bound_index(req[i][0]), lower_bound_index(req[i][1]));
            cout << req[i][1] - req[i][0] + 1 - p_sum << "\n";
        }
    }

    return 0;
}