#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int map[2001][2001];
int N, M;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet() : parent(100001), rank(100001, 1){
        for(int i = 1; i < 100001; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(n == parent[n]) return n;
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

int move_num[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool intheSpace(pair<int, int> data){
    if(1 <= data.first && data.first <= N && 
       1 <= data.second && data.second <= N) return true;
    else return false;
}

DisjointSet world;
queue<pair<int, int> > joint_set;
queue<pair<int, int> > progress_set;

void joint(){
    while(joint_set.size()!= 0){
        int x = joint_set.front().first;
        int y = joint_set.front().second;
        progress_set.push(joint_set.front());
        joint_set.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + move_num[i][0];
            int dy = y + move_num[i][1];
            if(!intheSpace(make_pair(dx, dy))) continue; // 범위 바깥에 있는 경우
            if(map[dx][dy] != 0 && (world.find(map[x][y]) != world.find(map[dx][dy]))){
                world.merge(map[x][y], map[dx][dy]);
                M--;
            } 

        }
    }
    return;
}

void progress(){
    while(progress_set.size() != 0){
        int x = progress_set.front().first;
        int y = progress_set.front().second;
        progress_set.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + move_num[i][0];
            int dy = y + move_num[i][1];
            if(!intheSpace(make_pair(dx, dy))) continue;
            // 진영이 없는 경우
            if(map[dx][dy] == 0){
                map[dx][dy] = map[x][y];
                joint_set.push(make_pair(dx, dy));
            }
            // 진영이 있는데 지금 현재 상태랑 다른 경우
            if(map[dx][dy] != 0 && world.find(map[x][y]) != world.find(map[dx][dy])){
                world.merge(map[x][y], map[dx][dy]);
                M--;
            }
        }
    }
    return;
}

int main(void){
    cin >> N >> M;

    memset(map, 0, sizeof(map));

    for(int i = 0; i < M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        map[temp1][temp2] = i + 1;
        joint_set.push(make_pair(temp1, temp2));
    }

    int count = 0;

    while(M > 1){
        joint();
        if(M == 1){
            cout << count << "\n";
            return 0;
        }
        progress();
        count++;
    }

    cout << count << "\n";
    return 0; 
}