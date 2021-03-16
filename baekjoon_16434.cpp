#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    ll n, atk;
    cin >> n >> atk;
    vector<vector<ll> > data_set(n);

    for(int i = 0; i < n; i++){
        ll temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        data_set[i].push_back(temp1);
        data_set[i].push_back(temp2);
        data_set[i].push_back(temp3);
    }
    ll start = 1;
    ll end = 2e17;

    while(start < end){
        ll mid = (start + end) / 2;
        ll current_hp = mid;
        ll current_atk = atk;
        bool check = true;
        for(int i = 0; i < n; i++){
            // 공격 타이밍
            if(data_set[i][0] == 1){
                if(data_set[i][2] % current_atk == 0){
                    current_hp -= ((data_set[i][2] / current_atk) - 1) * data_set[i][1];
                }
                else current_hp -= (data_set[i][2] / current_atk) * data_set[i][1];
                // 뒤진 상황
                if(current_hp <= 0){
                    start = mid + 1;
                    check = false;
                    break;
                }
            }
            else{
                current_hp = min(mid, current_hp + data_set[i][2]);
                current_atk += data_set[i][1];
            }
        }
        // 살아남은 경우
        if(check){
            end = mid;
        }
        else{
            start = mid + 1;

        }
    }

    cout << start << "\n";
    return 0;
}