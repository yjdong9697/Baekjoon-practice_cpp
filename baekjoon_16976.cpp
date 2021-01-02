#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;

    int temporary_store[600][600];
    int restore[300][300];

    for(int i = 0; i < 300; i++){
        for(int j = 0; j < 300; j++){
            restore[i][j] = -1;
        }
    }


    for(int i = 0; i < H + X; i++){
        for(int j = 0; j < W + Y; j++){
            int temp;
            cin >> temp;
            temporary_store[i][j] = temp;
        }
    }

    // 위 
    for(int i = 0; i < X; i++){
        for(int j = 0; j < W; j++){
            restore[i][j] = temporary_store[i][j];
        }
    }

    // 아래
    for(int i = H; i < X + H; i++){
        for(int j = Y; j < W + Y; j++){
            restore[i - X][j - Y] = temporary_store[i][j];
        }
    }
    
    // 오른쪽 옆
    for(int i = X; i < H; i++){
        for(int j = W; j < W + Y; j++){
            restore[i - X][j - Y] = temporary_store[i][j];
        }
    }

    // 왼쪽 옆
    for(int i = X; i < H; i++){
        for(int j = 0; j < Y; j++){
            restore[i][j] = temporary_store[i][j];
        }
    }

    // 나머지 체크(겹치는 부분 체크)
    for(int i = X; i < H; i++){
        for(int j = Y; j < W; j++){
            // 만약 여기가 -1이 아닌 경우
            if(restore[i][j] != -1){
                restore[i - X][j - Y] = temporary_store[i][j] - restore[i][j];
            }
            else{
                restore[i][j] = temporary_store[i][j] - restore[i - X][j - Y];
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W - 1; j++){
            cout << restore[i][j] << " ";
        }
        cout << restore[i][W - 1];
        cout << "\n";
    }

    return 0;
}