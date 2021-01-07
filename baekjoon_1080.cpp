#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool data_store[50][50];
bool compare_store[50][50];
int N, M;

// 왼쪽 상단 좌표 기준 9개 영역의 상대좌표 저장
int change_num[9][2] = {{0, 0}, {0, 1}, {0, 2},
                        {1, 0}, {1, 1}, {1, 2},
                        {2, 0}, {2, 1}, {2, 2}};
                        

// 행렬 내용물 반전시키는 함수
void change_value(int x, int y){
    for(int i = 0; i < 9; i++){
        int dx = x + change_num[i][0];
        int dy = y + change_num[i][1];
        data_store[dx][dy] = !data_store[dx][dy];
    }
}

int main(void){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < M ; j++){
            data_store[i][j] = temp[j] - '0';
        }
    } // Data_store

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < M ; j++){
            compare_store[i][j] = temp[j] - '0';
        }
    } // Compare Data_store

    int result = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(data_store[i][j] == compare_store[i][j]) continue;
            else{
                // 바꾸는게 애초에 불가능(3 x 3 박스 초과)
                if(i < 0 || i > N - 3 || j < 0 || j > M - 3){
                    cout << "-1\n";
                    return 0;
                }
                else{
                    change_value(i, j);
                    result += 1;
                }  
            }
        }
    }

    cout << result << "\n";
    return 0;
}