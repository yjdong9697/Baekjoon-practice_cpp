#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<int> first_circle, second_circle, third_circle, fourth_circle;
int right_index_first = 2;
int left_index_first = 6;
int right_index_second = 2;
int left_index_second = 6;
int right_index_third = 2;
int left_index_third = 6;
int right_index_fourth = 2;
int left_index_fourth = 6;

int rotate_condition_check[5] = {0};

int change_index(int index_num, int direction){
    // 시계 방향
    if(direction == 1){
        if(index_num == 0) return 7;
        else return index_num - 1;
    }
    // 반시계 방향
    else{
        if(index_num == 7) return 0;
        else return index_num + 1;
    }
}

// Condition  우측 : 1, 좌측 : 0
void rotate_check(int rotate_circle, int condition){
    if (rotate_circle > 4 || rotate_circle < 1) return; // Early exit
    if(rotate_circle == 1){
        // 우측 체크
        if(condition == 1){
            if(first_circle[right_index_first] == second_circle[left_index_second]) return;
            else{
                rotate_condition_check[rotate_circle + 1] = 1;
                rotate_check(rotate_circle + 1, 1);
                return;
            }
        }
        else return; // 좌측으로는 갈 수 없음

    }
    else if(rotate_circle == 2){
        // 우측 체크
        if(condition == 1){
            if(second_circle[right_index_second] == third_circle[left_index_third]) return;
            else{
                rotate_condition_check[rotate_circle + 1] = 1;
                rotate_check(rotate_circle + 1, 1);
                return;
            }
        }
        // 왼쪽 체크
        else{
            if(second_circle[left_index_second] == first_circle[right_index_first]) return;
            else{
                rotate_condition_check[rotate_circle - 1] = 1;
                rotate_check(rotate_circle - 1, 0);
                return;
            }
        }

    }
    else if(rotate_circle == 3){
        // 우측 체크
        if(condition == 1){
            if(third_circle[right_index_third] == fourth_circle[left_index_fourth]) return;
            else{
                rotate_condition_check[rotate_circle + 1] = 1;
                rotate_check(rotate_circle + 1, 1);
                return;
            }
        }
        // 왼쪽 체크
        else{
            if(third_circle[left_index_third] == second_circle[right_index_second]) return;
            else{
                rotate_condition_check[rotate_circle - 1] = 1;
                rotate_check(rotate_circle - 1, 0);
                return;
            }
        }

    }
    else{
        // 왼쪽 체크
        if(condition == 0){
            if(fourth_circle[left_index_fourth] == third_circle[right_index_third]) return;
            else{
                rotate_condition_check[rotate_circle - 1] = 1;
                rotate_check(rotate_circle - 1, 0);
                return;
            }
        }
        else return; // 우측으로는 갈 수 없음
    }
    return;
}

void change_index_fuc(int rotate_circle, int direction, int condition){
    if(rotate_circle < 1 || rotate_circle > 4) return; // Early exit
    if(rotate_circle == 1){
        if(rotate_condition_check[rotate_circle] == 1){
            right_index_first = change_index(right_index_first, direction);
            left_index_first = change_index(left_index_first, direction);
        }
        else return; // 돌아가지 않는 상황
        if(direction == 1){
            if(condition == 1) change_index_fuc(rotate_circle + 1, - 1, 1);
            else change_index_fuc(rotate_circle - 1, - 1, 0);
        }
        else{
            if(condition == 1) change_index_fuc(rotate_circle + 1, 1, 1);
            else change_index_fuc(rotate_circle - 1, 1, 0);
        }
        return;
    }
    else if(rotate_circle == 2){
        if(rotate_condition_check[rotate_circle] == 1){
            right_index_second = change_index(right_index_second, direction);
            left_index_second = change_index(left_index_second, direction);
        }
        else return; // 돌아가지 않는 상황
        if(direction == 1){
            if(condition == 1) change_index_fuc(rotate_circle + 1, - 1, 1);
            else change_index_fuc(rotate_circle - 1, - 1, 0);
        }
        else{
            if(condition == 1) change_index_fuc(rotate_circle + 1, 1, 1);
            else change_index_fuc(rotate_circle - 1, 1, 0);
        }
        return;

    }
    else if(rotate_circle == 3){
        if(rotate_condition_check[rotate_circle] == 1){
            right_index_third = change_index(right_index_third, direction);
            left_index_third = change_index(left_index_third, direction);
        }
        else return; // 돌아가지 않는 상황
        if(direction == 1){
            if(condition == 1) change_index_fuc(rotate_circle + 1, - 1, 1);
            else change_index_fuc(rotate_circle - 1, - 1, 0);
        }
        else{
            if(condition == 1) change_index_fuc(rotate_circle + 1, 1, 1);
            else change_index_fuc(rotate_circle - 1, 1, 0);
        }
        return;

    }
    else if(rotate_circle == 4){
        if(rotate_condition_check[rotate_circle] == 1){
            right_index_fourth = change_index(right_index_fourth, direction);
            left_index_fourth = change_index(left_index_fourth, direction);
        }
        else return; // 돌아가지 않는 상황
        if(direction == 1){
            if(condition == 1) change_index_fuc(rotate_circle + 1, - 1, 1);
            else change_index_fuc(rotate_circle - 1, - 1, 0);
        }
        else{
            if(condition == 1) change_index_fuc(rotate_circle + 1, 1, 1);
            else change_index_fuc(rotate_circle - 1, 1, 0);
        }
        return;
    }
}

int main(void){
    // 데이터 저장

    for(int i = 0; i < 8; i++){
        int temp;
        scanf("%1d", &temp);
        first_circle.push_back(temp);
    }
    for(int i = 0; i < 8; i++){
        int temp;
        scanf("%1d", &temp);
        second_circle.push_back(temp);
    }
    for(int i = 0; i < 8; i++){
        int temp;
        scanf("%1d", &temp);
        third_circle.push_back(temp);
    }
    for(int i = 0; i < 8; i++){
        int temp;
        scanf("%1d", &temp);
        fourth_circle.push_back(temp);
    }

    int change_num;
    cin >> change_num;

    for(int i = 0; i < change_num; i++){
        int change_circle, direction;
        cin >> change_circle >> direction;
        fill(rotate_condition_check, rotate_condition_check + 5, 0);
        rotate_condition_check[change_circle] = 1;
        rotate_check(change_circle, 1);
        rotate_check(change_circle, 0);
        change_index_fuc(change_circle, direction, 1);
        if(direction == 1){
            change_index_fuc(change_circle - 1, -1, 0);
        }
        else{
            change_index_fuc(change_circle - 1, 1, 0);
        }
    }

    for(int i = 0; i < 2; i++){
        right_index_first = change_index(right_index_first, 1);
        right_index_second = change_index(right_index_second, 1);
        right_index_third = change_index(right_index_third, 1);
        right_index_fourth = change_index(right_index_fourth, 1);
    }

    int result = 0;

    if(first_circle[right_index_first] == 1) result += 1;
    if(second_circle[right_index_second] == 1) result += 2;
    if(third_circle[right_index_third] == 1) result += 4;
    if(fourth_circle[right_index_fourth] == 1) result += 8;

    cout << result << "\n";
    return 0;
}