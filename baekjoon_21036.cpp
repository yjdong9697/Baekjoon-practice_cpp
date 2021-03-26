#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> market;

struct compare{
    bool operator()(market &d1, market &d2){
    return d1.first.first + d1.first.second < d2.first.first + d2.first.second;
    }
};

int main(void){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> data;
    data.push_back(-1);
    for(int i = 1; i <= m; i++){
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(),data.end()), data.end());

    if(k >= data.size() - 1){
        cout << n << "\n";
        return 0;
    }

    priority_queue<market, vector<market>, compare> pq;
    vector<market> store_temp(data.size());
    vector<int> visited(data.size(), 0);

    for(int i = 1; i <= data.size() - 1; i++){
        int left_value, right_value;
        // Left 가능한 값 체크
        if(i == 1){
            left_value = data[1] - 1;
        }
        else left_value = (data[i] - data[i - 1] - 1) / 2 + (data[i] - data[i - 1] - 1) % 2;
        // Right 가능한 값 체크
        if(i == data.size() - 1){
            right_value = n - data[i];   
        }
        else{
            right_value = (data[i + 1] - data[i] - 1) / 2 + (data[i + 1] - data[i] - 1) % 2;
        }
        // 우선순위 큐와 pq체크용도 배열에 저장
        pq.push(make_pair(make_pair(left_value, right_value), i));
        store_temp[i] = make_pair(make_pair(left_value, right_value), i);
    }

    int result = 0;
    for(int i = 0; i < k; i++){
        market check_value;
        // 만족할때까지 뽑음(즉, pq안에 있는 값과 체크용도 배열에 있는 값이 같을 때까지)
        while(true){
            check_value = pq.top(); pq.pop();
            if(check_value == store_temp[check_value.second] && visited[check_value.second] == 0){
                visited[check_value.second] = 1;
                break;
            }
            else continue;
        }
        result += (check_value.first.first + check_value.first.second + 1);
        int cur_index = check_value.second;
        // left check
        if(cur_index != 1){
            if((data[cur_index] - data[cur_index - 1] - 1) % 2 == 1){
                store_temp[cur_index - 1].first.second -= 1;
                pq.push(store_temp[cur_index - 1]);
            }
        }
        // right check
        if(cur_index != data.size() - 1){
            if((data[cur_index + 1] - data[cur_index] - 1) % 2 == 1){
                store_temp[cur_index + 1].first.first -= 1;
                pq.push(store_temp[cur_index + 1]);
            }
        }
    }
    cout << result << "\n";
    return 0;
}