#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef pair<int, int> pii;

int main(void){
    fastio;
    int N, K;
    cin >> N >> K;
    queue<pii> data;
    int visited[100001] = {0};
    visited[N] = 1;
    data.push(make_pair(N, 0));

    if(N == K){
        cout << 0 << "\n";
        cout << 1 << "\n";
        return 0;
    }

    int min_time = 987654321;
    int count_value = 0;

    while(data.size() != 0){
        pii check_value = data.front();
        data.pop();
        visited[check_value.first] = 1;

        if(check_value.second + 1 > min_time){
            cout << min_time << "\n";
            cout << count_value << "\n";

            return 0;
        }

        if(check_value.first + 1 == K || check_value.first - 1 == K || check_value.first * 2 == K){
            min_time = check_value.second + 1;
            if(check_value.first + 1 == K) count_value += 1;
            if(check_value.first - 1 == K) count_value += 1;
            if(check_value.first * 2 == K) count_value += 1;
            continue;
        }

        if(check_value.first * 2 <= 100000 && visited[check_value.first * 2] == 0){
            data.push(make_pair(check_value.first * 2, check_value.second + 1));

        } 
        if(check_value.first - 1 >= 0 && visited[check_value.first - 1] == 0){
            data.push(make_pair(check_value.first - 1, check_value.second + 1));

        }
        if(check_value.first + 1 <= 100000 && visited[check_value.first + 1] == 0){
            data.push(make_pair(check_value.first + 1, check_value.second + 1));
        } 
    }
    cout << min_time << "\n";
    cout << count_value << "\n";

    return 0;
}