#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    int r, c, t;
    cin >> r >> c >> t;

    int data_store[50][50];
    int air_cor_store;
    for(int i = 0; i < r; i++){
        for(int j= 0; j < c; j++){
            int temp;
            cin >> temp;
            data_store[i][j] = temp;
            if (temp == -1){
                air_cor_store = i; // air_cor is (i - 1, 0) and (i, 0)
            }
        }
    } // data store

    int recursion = 0;

    while(recursion < t){
        int data_temp[50][50] = {0};
        for(int i = 0; i < r; i++){
            for(int j= 0; j < c; j++){
                if(data_store[i][j] == 0 || data_store[i][j] == -1){
                    continue; // If store data is zero or air condition
                }
                else{
                    // Case 1 (위)
                    if(i - 1 >= 0){
                        if(data_store[i - 1][j] != -1){
                            data_temp[i - 1][j] += (data_store[i][j] / 5);
                            data_temp[i][j] -= (data_store[i][j] / 5);
                        }
                    }

                    // Case 2 (왼쪽)
                    if(j - 1 >= 0){
                        if(data_store[i][j - 1] != -1){
                            data_temp[i][j - 1] += (data_store[i][j] / 5);
                            data_temp[i][j] -= (data_store[i][j] / 5);
                        }
                    }

                    // Case 3 (오른쪽)
                    if(j + 1 < c){
                        if(data_store[i][j + 1] != -1){
                            data_temp[i][j + 1] += (data_store[i][j] / 5);
                            data_temp[i][j] -= (data_store[i][j] / 5);
                        }    
                    }

                    // Case 4 (아래)
                    if(i + 1 < r){
                        if(data_store[i + 1][j] != -1){
                            data_temp[i + 1][j] += (data_store[i][j] / 5);
                            data_temp[i][j] -= (data_store[i][j] / 5);
                        }                
                    }
                }
                
            }
        }

        // Sum data (Original + temp_data)
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                data_store[i][j] += data_temp[i][j];
            }
        }

        // Air_cor is (j - 1, 0) and (j, 0)

        // case 1(above)
        int first_x = air_cor_store - 1;
        int first_y = 1;
        int temp_store_first = 0;

        while(first_y < c){
            int temp = data_store[first_x][first_y];
            data_store[first_x][first_y] = temp_store_first;
            temp_store_first = temp;
            first_y += 1;
        }

        first_y -= 1;
        first_x -= 1; // 좌표 보정

        while(first_x >= 0){
            int temp = data_store[first_x][first_y];
            data_store[first_x][first_y] = temp_store_first;
            temp_store_first = temp;
            first_x -= 1;
        }

        first_x += 1;
        first_y -= 1; // 좌표 보정

        while(first_y >= 0){
            int temp = data_store[first_x][first_y];
            data_store[first_x][first_y] = temp_store_first;
            temp_store_first = temp;
            first_y -= 1;
            
        }

        first_y += 1;
        first_x += 1; // 좌표 보정

        while(first_x < air_cor_store - 1){
            int temp = data_store[first_x][first_y];
            data_store[first_x][first_y] = temp_store_first;
            temp_store_first = temp;
            first_x += 1;

        }

        // case 2(below)
        int second_x = air_cor_store;
        int second_y = 1;
        int temp_store_second = 0;

        while(second_y < c){
            int temp = data_store[second_x][second_y];
            data_store[second_x][second_y] = temp_store_second;
            temp_store_second = temp;
            second_y += 1;
        }

        second_y -= 1;
        second_x += 1; // 좌표 보정

        while(second_x < r){
            int temp = data_store[second_x][second_y];
            data_store[second_x][second_y] = temp_store_second;
            temp_store_second = temp;
            second_x += 1;
        }

        second_x -= 1;
        second_y -= 1; // 좌표 보정

        while(second_y >= 0){
            int temp = data_store[second_x][second_y];
            data_store[second_x][second_y] = temp_store_second;
            temp_store_second = temp;
            second_y -= 1;
            
        }

        second_y += 1;
        second_x -= 1; // 좌표 보정

        while(second_x > air_cor_store){
            int temp = data_store[second_x][second_y];
            data_store[second_x][second_y] = temp_store_second;
            temp_store_second = temp;
            second_x -= 1;

        }

        recursion += 1;
    }

    // 미세먼지 합 모으기 (단, -1이 2개 있는 것 고려해야 한다.)

    int sum = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            sum += data_store[i][j];
        }
    }

    cout << sum + 2 << "\n";
    return 0;
}