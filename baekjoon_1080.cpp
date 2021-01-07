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
                        
// data와 compare 사이에 다른 가장 왼쪽 상단 부분 좌표를 찾는 함수
// 만약 전부 똑같으면 pair(-1, -1) return
// 이외에는 다른 가장 왼쪽 상단 부분 좌표 return
pair<int, int> find_top_left(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(data_store[i][j] != compare_store[i][j]){
                return make_pair(i, j);
            }
        }
    }
    // 다른게 없는 경우 (-1, -1) Return
    return make_pair(-1, -1);
}

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

    while(true){
        pair<int, int> top_left = find_top_left();

        // 전부 바꾸기 완료(즉, data와 compare사이에 다른 것이 없음)
        if(top_left == make_pair(-1, -1)){
            cout << result << "\n";
            return 0;
        }

        // 바꾸는게 애초에 불가능(3 x 3 박스 초과)
        if(top_left.first < 0 || top_left.first > N - 3 || top_left.second < 0 || top_left.second > M - 3){
            cout << "-1\n";
            return 0;
        }
        // 
        else{
            change_value(top_left.first, top_left.second);
            result += 1;
        }
    }
}