#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int visited[9] = {0};
int result_store[9] = {0};

void result(int number){
    if(number == M){
        for(int i = 0; i < M; i++){
            cout << result_store[i] << " ";
        }
        cout << "\n";
        return;
    }
    else{
        for(int i = 1; i <= N; i++){
            if(visited[i] == 0){
                result_store[number] = i;
                visited[i] = 1;
                result(number + 1);
                visited[i] = 0;
            }
        }
        return;
    }
}


int main(void){
    cin >> N >> M;

    result(0);

    return 0;
}