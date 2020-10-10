#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int up, down, total;
int check_num = 2147483647;
bool visited[1000001] = {false};

int main(void){
    int current, purpose;
    cin >> total >> current >> purpose >> up >> down; // 문제에서 입력하는 값
    queue <pair<int,int> > bfs;

    pair<int,int> first_element; // 층을 first element, 이동횟수를 second element
    first_element.first = current;
    first_element.second = 0;
    bfs.push(first_element);
    visited[current] = 1;

    while(bfs.size() != 0){
        if(bfs.front().first == purpose){
            check_num = bfs.front().second;
            break; // 만약 가장 앞에 있는 것이 목적하는 것이라면, 이동횟수 저장
        }
        else{
            int temp = bfs.front().first;
            int depth_temp = bfs.front().second;
            bfs.pop();
            pair<int,int> up_case;
            pair<int,int> down_case; // up_case와 down_case를 각각 판단
            up_case.first = temp + up;
            up_case.second = depth_temp + 1;
            down_case.first = temp - down;
            down_case.second = depth_temp + 1;

            if(temp + up > total && temp - down <= 0){ // 범위 초과 check
                break;
            }
            else if(temp + up > total){
                if(visited[down_case.first] == false){
                    bfs.push(down_case);
                    visited[down_case.first] = true;
                }
                
            }
            else if(temp - down <= 0){
                if(visited[up_case.first] == false){
                    bfs.push(up_case);
                    visited[up_case.first] = true;
                }
            }
            else{
                if(visited[down_case.first] == false){
                    bfs.push(down_case);
                    visited[down_case.first] = true;
                }
                if(visited[up_case.first] == false){
                    bfs.push(up_case);
                    visited[up_case.first] = true;
                }
            }
        }
    }

    if(check_num != 2147483647){
        cout << check_num << "\n";
    }
    else{
        cout << "use the stairs\n";
    }

}