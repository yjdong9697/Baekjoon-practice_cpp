#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;

int seg[400000];

bool compare(piiii &v1, piiii & v2){
    return v1.first.second > v2.first.second;
}

void update(int node_index, int node_left, int node_right, int index){
    if(index < node_left || node_right < index) return;
    seg[node_index]++;
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index);
    update(node_index * 2 + 1, mid + 1, node_right, index);
    return;
}

int query(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right) +
           query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));
    int N;
    cin >> N;
    vector<int> data(N); // 수열 저장
    for(int i = 0; i < N; i++){
        cin >> data[i];
    }
    
    int M;
    cin >> M;
    vector<piiii> query_value;
    vector<int> value_store; // k값 묶어둔 것
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        query_value.push_back(make_pair(make_pair(make_pair(a, b), c),i));
        value_store.push_back(c);
    }

    sort(query_value.begin(), query_value.end(), compare); // 주어진 쿼리를 k가 큰 순서대로 정렬

    // k값 압축 및 정렬
    sort(value_store.begin(), value_store.end());
    value_store.erase(unique(value_store.begin(), value_store.end()), value_store.end());
    
    map<int, int> index;
    for(int i = 0; i < value_store.size(); i++){
        index.insert(make_pair(value_store[i], i));
    } // k값 자체를 index로 매핑해주는 map 자료구조

    // 자기보다 작은 k중 가장 큰 것 찾기(Lower bound 사용)
    vector<int> update_store[value_store.size()];
    for(int i = 0; i < N; i++){
        int start = 0;
        int end = value_store.size();
        while(start < end){
            int mid = (start + end) / 2;
            if(data[i] > value_store[mid]) start = mid + 1;
            else end = mid;
        }
        if(start >= 1) update_store[start - 1].push_back(i);       
    }

    vector<int> result(M);

    for(int i = 0; i < M; i++){
        int k = query_value[i].first.second;
        // 업데이트
        for(int j = 0; j < update_store[index[k]].size(); j++){
            update(1, 0, N - 1, update_store[index[k]][j]);
        }
        update_store[index[k]].clear();
        result[query_value[i].second] = query(1, 0, N - 1, query_value[i].first.first.first - 1, query_value[i].first.first.second - 1);
    }

    for(int i = 0; i < M; i++){
        cout << result[i] << "\n";
    }

    return 0;
}