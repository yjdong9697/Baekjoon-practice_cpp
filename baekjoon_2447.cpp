// 아이디어는 대략적으로 맞는데, 다차원배열 포인터 및 vector 학습이 아직은 모자라서 구현이 안됨

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char blank_maker(int,int, int, char * setting);

int main(void){
    int n;
    cin >> n;

    vector<vector<char>> setting (27,(27,'*'));
    fill(setting, setting + 27 * 27, '*'); // initial setting

    blank_maker(27, 0, 0, setting);
    return 0;

}

int blank_maker(int n, int x, int y , char * setting_point){

    if (n == 1){
        return 0; // early exit
    }
    
    for(int i = 0; i < n / 3; i++){
        setting_point = setting_point += 3/n + i;
        for(int j = 0; j < n / 3; j++){
            setting_point[y + 3/n + j] = " ";
        }
    }

    for (int i = 0; i < 3; i++){
        blank_maker(n / 3, x, y + i * (3 / n), setting_point);
    } //above

    blank_maker(n / 3, x + (3 / n), y, setting_point);
    blank_maker(n / 3, x + (3 / n), y + 2 * (3 / n), setting_point); //middle

    for (int i = 0; i < 3; i++){
        blank_maker(n/3, x + 2 * (3 / n), y + i * (3 / n), setting_point);
    } //above

    return 0;



    



}