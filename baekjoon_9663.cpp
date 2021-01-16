#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int up_down[16];
int right_left[16];
int cross_first[32];
int cross_second[32];
int N;
ll result = 0;

void backtrack(int check_num){
    if(check_num == N){
        result += 1;
        return;
    }
    else{
        for(int i = 0; i < N; i++){
            if(right_left[i] == 1) continue; // Already visit
            bool available_check = false;
            for(int j = 0; j < N; j++){
                if(up_down[j] == 1) ;
                else{
                    if(cross_first[i + j] == 0 && cross_second[i - j + (N - 1)] == 0){
                        right_left[i] = 1;
                        up_down[j] = 1;
                        cross_first[i + j] = 1;
                        cross_second[i - j + (N - 1)] = 1;
                        backtrack(check_num + 1);
                        right_left[i] = 0;
                        up_down[j] = 0;
                        cross_first[i + j] = 0;
                        cross_second[i - j + (N - 1)] = 0;
                        available_check = true;
                    }
                }
            }
            break;
        }
        return;
    }
}

int main(void){
    cin >> N;

    backtrack(0);

    cout << result << "\n";
    return 0;
    
}