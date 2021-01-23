#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define INF 123456789

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n] == n) return n;
        else{
            return parent[n] = find(parent[n]);
        }
    }

    void merge(int n, int m){
        n = find(n); m = find(m);
        if(n == m) return;
        if(rank[n] < rank[m]) swap(n, m);
        parent[m] = n;
        if(rank[n] == rank[m]) rank[n]++;
        return;
    }
};

struct node_data{
    int start;
    int end;
    int cost;
    node_data(int temp1, int temp2, int temp3) : start(temp1), end(temp2), cost(temp3)
    {}
};

struct compare{
    bool operator()(const node_data &data1, const node_data &data2){
        return data1.cost < data2.cost;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p, w;
    cin >> p >> w;
    int c, v;
    cin >> c >> v;

    priority_queue<node_data, vector<node_data>, compare> pq;
    DisjointSet world(p + 1);

    for(int i = 0; i < w; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        pq.push(node_data(temp1, temp2, temp3));
    }

    int min_store = INF;

    while(pq.size() != 0){
        if(world.find(c) == world.find(v)) break;
        
        if(world.find(pq.top().start) == world.find(pq.top().end)){
            pq.pop();
        }
        else{
            world.merge(pq.top().start, pq.top().end);
            min_store = min(min_store, pq.top().cost);
            pq.pop();
        }
    }

    cout << min_store << "\n";

    return 0;
}