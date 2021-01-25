#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet() : parent(1001){
        for(int i = 0; i < 1001; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(n == parent[n]) return n;
        if(parent[n] < 0) return parent[n];
        else return parent[n] = find(parent[n]);
    }

    void merge(int n, int m){
        n = find(n); m = find(m);
        if(n == m) return;
        parent[m] = n;
        return;
    }
};

struct node{
    int start;
    int end;
    int cost;
    node(int temp1, int temp2, int temp3) : start(temp1), end(temp2), cost(temp3)
    {}
};

struct compare{
    bool operator ()(const node &data1, const node &data2){
        return data1.cost > data2.cost;
    }
};

DisjointSet world;

int N, M, K;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    priority_queue<node, vector<node>, compare> pq;

    for(int i = 0; i < K; i++){
        int temp;
        cin >> temp;
        world.parent[temp] = - world.parent[temp];
    }

    for(int i = 0; i < M; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        pq.push(node(temp1, temp2, temp3));
    }

    int count = 0;

    while(pq.size() != 0){
        if(world.find(pq.top().start) < 0 && world.find(pq.top().end) < 0){
            pq.pop(); // 둘 다 연결된 상황
        }
        else if(world.find(pq.top().start) < 0 && world.find(pq.top().end) > 0){
            world.merge(pq.top().start, pq.top().end);
            count += pq.top().cost;
            pq.pop();
        }
        else if(world.find(pq.top().start) > 0 && world.find(pq.top().end) < 0){
            world.merge(pq.top().end, pq.top().start);
            count += pq.top().cost;
            pq.pop();

        }
        else{
            if(world.find(pq.top().start) == world.find(pq.top().end)){
                pq.pop();
                continue;
            }
            world.merge(pq.top().end, pq.top().start);
            count += pq.top().cost;
            pq.pop();
        }
    }

    cout << count << "\n";
    return 0;
    
}