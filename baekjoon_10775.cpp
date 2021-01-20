#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int G, P;

struct DisjointSet{
    vector<int> parent;
    // Constructor
    DisjointSet(int N) : parent(N){
        for(int i = 0 ; i < N; i++){
            parent[i] = i;
        }
    }
    // U가 속한 트리의 루트를 반환
    int find(int u){
        if(parent[u] == u) return u;
        else{
            return parent[u] = find(parent[u]);
        }
    }

    // U와 V가 속한 트리를 병합
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        // u가 무조건 더 작게끔
        if(u > v) swap(u, v);
        parent[v] = u;
        return; 
    }
};

int main(void){
    cin >> G;
    cin >> P;
    
    DisjointSet Disjoint(G + 1);

    for(int i = 0; i < P; i++){
        int temp;
        cin >> temp;
        int check_num = Disjoint.find(temp);
        if(check_num == 0){
            cout << i << "\n";
            return 0;
        }
        Disjoint.merge(check_num, check_num -1);
    }

    cout << P << "\n";

    return 0;
}