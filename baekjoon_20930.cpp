#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef pair<int, int> pii;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }// Path compression

    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return; // Already Merged;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u; // Union by rank
        if(rank[u] == rank[v]) rank[u]++;
        return;
    }
};

int main(void){
    fastio;
    int N, Q;
    cin >> N >> Q;
    vector<pair<pii, int> > path_x_store(N);
    vector<pair<pii, int> > path_y_store(N);
    DisjointSet world(N);
    for(int i = 0; i < N; i++){
        int sx, sy, fx, fy;
        cin >> sx >> sy >> fx >> fy;
        path_x_store[i] = make_pair(make_pair(min(fx, sx), max(fx, sx)), i);
        path_y_store[i] = make_pair(make_pair(min(fy, sy), max(fy, sy)), i);
    }

    sort(path_x_store.begin(), path_x_store.end());
    sort(path_y_store.begin(), path_y_store.end());

    for(int i = 1; i < N; i++){
        if(path_x_store[i - 1].first.second >= path_x_store[i].first.first){
            world.merge(path_x_store[i - 1].second, path_x_store[i].second);
        }
    }

    for(int i = 1; i < N; i++){
        if(path_y_store[i - 1].first.second >= path_y_store[i].first.first){
            world.merge(path_y_store[i - 1].second, path_y_store[i].second);
        }
    }

    for(int i = 0; i < Q; i++){
        int check1, check2;
        cin >> check1 >> check2;
        if(world.find(check1 - 1) == world.find(check2 - 1)){
               cout << 1 << "\n";
        }
        else cout << 0 << "\n";
    }

    return 0;
}