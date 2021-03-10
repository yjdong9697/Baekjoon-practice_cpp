#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void){
    fastio;
    int n;
    cin >> n;
    vector<pii> q;
    for(int i = 0; i < n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        q.push_back(make_pair(temp1, temp2));
    }
    sort(q.begin(), q.end());
    
    int d, energy;
    cin >> d >> energy;

    int current_pos = 0; // 현재 위치
    int visited_num = 0;
    int current_index = 0;
    
    priority_queue<int> pq;

    while(current_index < n){
        pii next_gas = q[current_index];
        // 연료는 빵빵
        if(energy >= next_gas.first - current_pos){
            pq.push(next_gas.second);
            energy -= (next_gas.first - current_pos);
            current_pos = next_gas.first;
        }
        // 연료 부족
        else{
            while(!pq.empty()){
                energy += pq.top();
                pq.pop();
                visited_num += 1;
                if(energy >= (next_gas.first - current_pos)) break; // 연료 채울만큼 방문
            }
            // 모자라서 끝난 경우
            if(energy < (next_gas.first - current_pos)){
                cout << -1 << "\n";
                return 0;
            }
            else{
                pq.push(next_gas.second);
                energy -= (next_gas.first - current_pos);
                current_pos = next_gas.first;
            }
        }
        current_index++;
    }
    if(current_pos < d){
        // 에너지 충분히 남은 상황
        if(energy >= (d - current_pos)){
            cout << visited_num << "\n";
            return 0;
        }
        else{
            while(!pq.empty()){
                energy += pq.top();
                pq.pop();
                visited_num += 1;
                if(energy >= (d - current_pos)) break;
            }
            if(energy < (d - current_pos)){
                cout << -1 << "\n";
                return 0;
            }
            else{
                cout << visited_num << "\n";
                return 0;
            }
        }
    }
}