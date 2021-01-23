#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;
int visited[1001];

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

struct path{
    int start;
    int end;
    int price;
    path(int temp1, int temp2, int temp3) : start(temp1), end(temp2), price(temp3) 
    {}
};

struct compare{
    bool operator()(const path &data1, const path &data2){
        if(data1.price == data2.price){
            return data1.start > data2.start;
        }
        else return data1.price > data2.price;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(visited, 0, sizeof(visited)); // 방문 0으로 초기화
    int N, M;
    cin >> N;
    cin >> M;

    priority_queue<path, vector<path>, compare> pq;
    DisjointSet world(N + 1);

    for(int i = 0; i < M; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        pq.push(path(temp1, temp2, temp3));
    } // 길 정보 저장

    int current_price = 0;
    while(pq.size() != 0){
        if(world.find(pq.top().start) == world.find(pq.top().end)){
            pq.pop();
        }
        else{
            world.merge(pq.top().start, pq.top().end);
            current_price += pq.top().price;
            pq.pop();
        }
    }

    cout << current_price << "\n";

    return 0;
}