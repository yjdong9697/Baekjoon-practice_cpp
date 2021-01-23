#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int n, m, k;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n] == n) return n;
        else return parent[n] = find(parent[n]);
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

struct compare1{
    bool operator()(const node_data &data1, const node_data &data2){
        return data1.cost < data2.cost;
    }
};

struct compare2{
    bool operator()(const node_data &data1, const node_data &data2){
        return data1.cost > data2.cost;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0) return 0;
        DisjointSet world_high(n + 1);
        DisjointSet world_low(n + 1);
        priority_queue<node_data, vector<node_data>, compare1> pq_high;
        priority_queue<node_data, vector<node_data>, compare2> pq_low;
        
        for(int i = 0; i < m; i++){
            char color;
            int temp1, temp2;
            cin >> color >> temp1 >> temp2;
            if(color == 'B'){
                pq_high.push(node_data(temp1, temp2, 1));
                pq_low.push(node_data(temp1, temp2, 1));
            }
            else{
                pq_high.push(node_data(temp1, temp2, 0));
                pq_low.push(node_data(temp1, temp2, 0));
            }
        } // Node data store

        int high_sum = 0;
        while(pq_high.size() != 0){
            // 이미 같은 집합 안에 있는 경우
            if(world_high.find(pq_high.top().start) == world_high.find(pq_high.top().end)){
                pq_high.pop();
            }
            else{
                world_high.merge(pq_high.top().start, pq_high.top().end);
                high_sum += pq_high.top().cost;
                pq_high.pop();
            }
        }

        int low_sum = 0;
        while(pq_low.size() != 0){
            // 이미 같은 집합 안에 있는 경우
            if(world_low.find(pq_low.top().start) == world_low.find(pq_low.top().end)){
                pq_low.pop();
            }
            else{
                world_low.merge(pq_low.top().start, pq_low.top().end);
                low_sum += pq_low.top().cost;
                pq_low.pop();
            }
        }

        if(low_sum <= k && k <= high_sum){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
}