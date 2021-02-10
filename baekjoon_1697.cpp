#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef pair<int, int> pii;

int main(void){
    fastio;
    int N, K;
    cin >> N >> K;
    queue<pii> data;
    int visited[2000001] = {0};
    data.push(make_pair(N, 0));

    if(N == K){
        cout << 0 << "\n";
        return 0;
    }

    while(true){
        pii check_value = data.front();
        data.pop();

        if(check_value.first + 1 == K || check_value.first - 1 == K || check_value.first * 2 == K){
            cout << check_value.second + 1 << "\n";
            return 0;
        }

        if(check_value.first * 2 <= 200000 && visited[check_value.first * 2] == 0){
            data.push(make_pair(check_value.first * 2, check_value.second + 1));
            visited[check_value.first * 2] = 1;
        } 
        if(check_value.first - 1 >= 0 && visited[check_value.first - 1] == 0){
            data.push(make_pair(check_value.first - 1, check_value.second + 1));
            visited[check_value.first - 1] = 1;

        }
        if(check_value.first + 1 <= 200000 && visited[check_value.first + 1] == 0){
            data.push(make_pair(check_value.first + 1, check_value.second + 1));
            visited[check_value.first + 1] = 1;
        }   
    }
}