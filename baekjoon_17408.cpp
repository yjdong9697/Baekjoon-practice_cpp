#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

class max_store{
    public:
    int max_1;
    int max_2;
    max_store(){
        max_1 = -1;
        max_2 = -1;
    }
    max_store(int a){
        max_1 = a;
        max_2 = -1;
    }
    max_store(int a, int b){
        max_1 = a;
        max_2 = b;
    }
};

max_store seg[400000];

void update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return;
    if(node_left == node_right){       
        seg[node_index] = max_store(value);
        return;       
    }
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index, value);
    update(node_index * 2 + 1, mid + 1, node_right, index, value);
    vector<int> d;
    d.push_back(seg[node_index * 2].max_1);
    d.push_back(seg[node_index * 2].max_2);
    d.push_back(seg[node_index * 2 + 1].max_1);
    d.push_back(seg[node_index * 2 + 1].max_2);
    sort(d.begin(), d.end());
    seg[node_index] = max_store(d[d.size() - 1], d[d.size() - 2]);
    return;
}

max_store query(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return max_store();
    if(query_left <= node_left && node_right <= query_right){
        return seg[node_index];
    }
    int mid = (node_left + node_right) / 2;
    max_store v1 = query(node_index * 2, node_left, mid, query_left, query_right);
    max_store v2 = query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
    vector<int> d;
    d.push_back(v1.max_1);
    d.push_back(v1.max_2);
    d.push_back(v2.max_1);
    d.push_back(v2.max_2);
    sort(d.begin(), d.end());
    return max_store(d[d.size() - 1], d[d.size() - 2]);
}

int main(void){
    fastio;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int d;
        cin >> d;
        update(1, 1, n, i, d);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1, 1, n, b, c);
        }
        else{
            max_store result = query(1, 1, n, b, c);
            cout << result.max_1 + result.max_2 << "\n";
        }
    }
    return 0;
}