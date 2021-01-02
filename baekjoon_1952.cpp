#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n;
int change_num = 0;
int count_store = 1;

// 방향 바꿔주는 함수
int change_direction(int direction){
    if(direction == 3){
        return 0;
    }
    else{
        return direction + 1;
    }
}

// 다음 칸이 유효칸 칸인지 체크 (0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽)
// 1 : 유효한 칸
// 0 : 무효한 칸
int available_check(int direction, int x_pos, int y_pos, int** data){
    if(direction == 0){
        if(x_pos - 1 >= 0){
            if(data[x_pos -1][y_pos] == 1) return 0;
            else return 1;
        }
        else return 0;
    }
    else if(direction == 1){
        if(y_pos + 1 < n){
            if(data[x_pos][y_pos + 1] == 1) return 0;
            else return 1;
        }
        else return 0;

    }
    else if(direction == 2){
        if(x_pos + 1 < m){
            if(data[x_pos + 1][y_pos] == 1) return 0;
            else return 1;
        }
        else return 0;
    }
    else{
        if(y_pos -1 >= 0){
            if(data[x_pos][y_pos -1] == 1) return 0;
            else return 1;
        }
        else return 0;
    }
}

// Change the saved position value
void change_pos(int direction, int x_pos, int y_pos, int** data){
    if(direction == 0){
        data[x_pos - 1][y_pos] = 1;
        return;
    }
    else if(direction == 1){
        data[x_pos][y_pos + 1] = 1;
        return;
    }
    else if(direction == 2){
        data[x_pos + 1][y_pos] = 1;
        return;
    }
    else{
        data[x_pos][y_pos - 1] = 1;
        return;
    }
}

void foward(int direction, int x_pos, int y_pos, int** data){
    if(count_store == m * n) return; // 전부 다 돌은 경우

    // 무효한 칸인 경우
    if(available_check(direction, x_pos, y_pos, data) == 0){
        change_num += 1;
        foward(change_direction(direction), x_pos, y_pos, data);
        return;
    }
    // 유효한 칸인 경우
    else{
        change_pos(direction, x_pos, y_pos, data);
        count_store += 1;
        if(direction == 0){
            foward(direction, x_pos - 1, y_pos, data);
            return;
        }
        else if(direction == 1){
            foward(direction, x_pos, y_pos + 1, data);
            return;
        }
        else if(direction == 2){
            foward(direction, x_pos + 1, y_pos, data);
            return;
        }
        else{
            foward(direction, x_pos, y_pos - 1, data);
            return;
        }    
    }
}



int main(void){
    cin >> m >> n; // input value

    // 0 : 위쪽으로 이동
    // 1 : 오른쪽으로 이동
    // 2 : 아래쪽으로 이동
    // 3 : 왼쪽으로 이동
    int current_status = 2;

    int** data_store = new int*[m];
    for(int i = 0; i < m; i++){
        data_store[i] = new int[n];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            data_store[i][j] = 0;
        }
    }
    data_store[0][0] = 1;

    foward(1, 0, 0, data_store);

    cout << change_num << "\n";

    // Deallocate
    for(int i = 0; i < m; i++){
        delete[] data_store[i];
    }
    delete[] data_store;

    return 0;
}