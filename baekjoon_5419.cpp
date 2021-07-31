#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool compare(pii v1, pii v2){
    if(v1.second == v2.second){
        return v1.first > v2.first;
    }
    else return v1.second < v2.second;
}

ll seg[300000];

void update(int node_index, int node_left, int node_right, int index){
    if(index < node_left || node_right < index) return;
    seg[node_index]++;
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index);
    update(node_index * 2 + 1, mid + 1, node_right, index); 
}

ll query(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right) +
           query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
}

int main(void){
    fastio;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(seg, 0, sizeof(seg));
        int n;
        cin >> n;
        vector<int> x_compress;
        vector<pii> cor;
        map<int, int> index;
        
        x_compress.push_back(-1000000001);
        for(int j = 1; j <= n; j++){
            int x, y;
            cin >> x >> y;
            x_compress.push_back(x);
            cor.push_back(make_pair(x, y));
        }
        sort(x_compress.begin(), x_compress.end());
        x_compress.erase(unique(x_compress.begin(), x_compress.end()), x_compress.end());

        for(int j = 1; j <= x_compress.size(); j++){
            index.insert(make_pair(x_compress[j], j));
        }

        vector<int> num_store(x_compress.size(), 0);
        for(int i = 0; i < n; i++){
            int x = cor[i].first;
            num_store[index[x]]++;
        }

        // y가 작은 것이 더 먼저(같은 경우에는 x가 더 큰 것이 위치하게끔)
        sort(cor.begin(), cor.end(), compare);
        
        ll result = 0;
        for(int i = 0; i < n; i++){
            int index_value = index[cor[i].first];
            result += query(1, 1, x_compress.size() - 1, index_value + 1, x_compress.size() - 1);
            update(1, 1, x_compress.size() - 1, index_value);
        }

        for(int i = 1; i < num_store.size(); i++){
            result += num_store[i] * (num_store[i] - 1) / 2;
        }

        cout << result << "\n";
 
    }
    return 0;
}