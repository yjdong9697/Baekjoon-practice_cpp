#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;
typedef long long ll;

struct line{
    int start;
    int end;
    int num;
    line(int temp1, int temp2, int temp3) : start(temp1), end(temp2), num(temp3 + 1)
    {}
};

bool compare(const line &data1, const line &data2){
    if(data1.start == data2.start){
        return data1.end < data2.end;
    }
    else return data1.start < data2.start;
}

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
        else{
            if(rank[n] < rank[m]) swap(n, m);
            parent[m] = n;
            if(rank[n] == rank[m]) rank[n]++;
            return;
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    vector<line> data_store;
    data_store.push_back(line(-1,-1,0)); // Trasn data)

    cin >> N >> Q;

    DisjointSet world(N + 1);

    for(int i = 0; i < N; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        data_store.push_back(line(temp1, temp2, i));
    } // Data store

    sort(data_store.begin(), data_store.end(), compare);

    for(int i = 1; i < N; i++){
        if(data_store[i].end >= data_store[i + 1].start){
            world.merge(data_store[i].num, data_store[i + 1].num);
            data_store[i + 1].end = max(data_store[i].end, data_store[i + 1].end);
        }
    }

    for(int i = 0; i < Q; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if(world.find(temp1) == world.find(temp2)){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}