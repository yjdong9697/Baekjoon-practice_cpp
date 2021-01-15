#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int output_store[9] = {0};


void check_function(int count, int max_store){
    // 출력 시점이 왔다
    if(count == M){
        for(int i = 0; i < M; i++){
            cout << output_store[i] << " ";
        }
        cout << "\n";
        return;
    }
    else{
        for(int i = 1; i <= N; i++){
            // NOt visited check
            if(max_store < i){
                output_store[count] = i;
                check_function(count + 1, i);
            } 
        }
        return;
    }

}

int main(void){
    cin >> N >> M;

    check_function(0, 0);

    return 0;
}