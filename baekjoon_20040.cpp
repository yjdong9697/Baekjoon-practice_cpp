#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int visited[500000] = {0};

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
        // 무조건적으로 rank가 n이 더 크게 끔 설정
        if(rank[n] < rank[m]) swap(n, m);
        parent[m] = n;
        if(rank[n] == rank[m]) rank[n]++;
        return;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    DisjointSet world(N);

    for(int i = 0; i < M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if(world.find(temp1) == world.find(temp2)){
            cout << i + 1 << "\n";
            return 0;
        }
        else{
            world.merge(temp1, temp2);
        }
    }

    cout << 0 << "\n";

    return 0;
}