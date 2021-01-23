#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <string>
#define INF 123456789

using namespace std;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1){
        for(int i = 0; i < n ; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(n == parent[n]) return n;
        else return parent[n] = find(parent[n]);
    } // Path compression은 진행하지 않음

    void merge(int n, int m){
        n = find(n); m = find(m);
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

    int N, Q;
    cin >> N >> Q;
    DisjointSet world(N + 1);
    vector<int> parent_store(N + 1);
    for(int i = 1; i < N; i++){
        parent_store[i] = i;
    }
    stack<int> delete_store;
    stack<pair<int, int> > check_store;
    vector<int> check_order; // 0은 지우는 경우, 1은 삽입하는 경우

    for(int i = 1; i <= N - 1; i++){
        int temp;
        cin >> temp;
        parent_store[i + 1] = temp;
    }

    for(int i = 0; i < (N - 1) + Q; i++){
        int check_num;
        cin >> check_num;
        // 지우는 경우
        if(check_num == 0){
            int check_node;
            cin >> check_node;
            delete_store.push(check_node);
            check_order.push_back(0);
        }
        // 확인하는 경우
        else{
            int check1, check2;
            cin >> check1 >> check2;
            check_store.push(make_pair(check1, check2));
            check_order.push_back(1);
        }
    }

    stack<bool> print_message;

    while(check_order.size() != 0){
        int check_num = check_order.back();
        // 지우는 경우
        if(check_num == 0){
            int merge_num = delete_store.top();
            world.merge(merge_num, parent_store[merge_num]);
            delete_store.pop();
        }
        // 추가하는 경우
        else{
            if(world.find(check_store.top().first) == world.find(check_store.top().second)){
                print_message.push(true);
            }
            else print_message.push(false);
            check_store.pop();
        }
        check_order.pop_back();
    }

    while(print_message.size() != 0){
        cout << (print_message.top()? "YES" : "NO") << "\n";
        print_message.pop();
    }
    return 0;
}