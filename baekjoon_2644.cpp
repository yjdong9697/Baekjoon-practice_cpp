#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int visited[101] = {0};

int dfs(int start, int end, int (&data_store)[101][101]){
    if(start == end) return 0;
    if(visited[start] == 1) return 0;
    else{
        int count = 0;
        visited[start] = 1;
        for(int i = 0; i < 101; i++){
            if(visited[i] != 1){
                if(data_store[start][i] == 1){
                    if(i == end){
                        return 1;
                    }
                    else{
                        int check_num = dfs(i, end, data_store);
                        if (check_num > 0){
                            return 1 + check_num;
                        }
                    }      
                }
            }
            
        }
        return -1; // 안나온 경우
    }
}

int main(void){
    int n;
    cin >> n; // 사람의 수

    int check_people1, check_people2;
    cin >> check_people1 >> check_people2;
    int data_store[101][101] = {0};

    int node_num;
    cin >> node_num;

    for(int i = 0; i < node_num; i++){
        int temp;
        cin >> temp;
        int push_data;
        cin >> push_data;
        data_store[temp][push_data] = 1;
        data_store[push_data][temp] = 1;
    } // data_store

    cout << dfs(check_people1, check_people2, data_store);

    return 0;
}