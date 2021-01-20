#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
typedef long double ld;

using namespace std;

int worker_num;
ll total_cost;

struct people{
    ld k; // 최저 임금 / 자격증 수 
    int quality; // 인부 자격증 수 
    int num; // 인부 인덱스
    people(int temp1, int temp2, int temp3);
};

people::people(int temp1, int temp2, int temp3){
    k = (ld)temp1 / temp2;
    quality = temp2;
    num = temp3 + 1;
    
}

bool compare(const people& data1, const people& data2){
    return data1.k < data2.k;
}

bool compare2(const people& data1, const people& data2){
    return data1.quality < data2.quality;
}

int main(void){
    cin >> worker_num >> total_cost;
    vector<people> data_store;
    
    for(int i = 0; i < worker_num; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        data_store.push_back(people(temp1, temp2, i));
    }

    // k 순서대로 정렬함
    sort(data_store.begin(), data_store.end(), compare);

    priority_queue<int, vector<int>, less<int> > pq; // 자격증 수가 큰 것부터 삭제
    ll total_quality = 0; // pq안에 들어있는 자격증 수의 합을 미리 저장해둠
    int max_worker_num = 0; // 인부 수가 최대일 때 인부의 수 저장
    int max_quality = 0; // 인부 수가 최대일 때의 pq에서의 자격증의 최댓값 저장
    int max_index = 0; // 인부 수가 최대일 때의 i를 저장
    ld min_cost = 10000000001ll;

    for(int i = 0; i < worker_num; i++){
        pq.push(data_store[i].quality);
        total_quality += data_store[i].quality; // pq안에 들어있는 자격증 수 업데이트
        ld current_k = data_store[i].k; // 비례 상수 업데이트
        // 최대 할당 비용이 넘지 않을 때까지 인부를 줄임
        while(total_quality * current_k > total_cost){
            total_quality -= pq.top();
            pq.pop();
        }
        // 최대 인부수인경우
        if(max_worker_num < pq.size()){
            max_worker_num = pq.size();
            max_index = i;
            max_quality = pq.top();
            min_cost = total_quality * current_k;
        }
        // 과거 최대 인부수와 같은 경우 : 최소 임금일 때를 찾고 해당하는 정보를 저장
        else if(max_worker_num == pq.size()){
            if(total_quality * current_k < min_cost){
                max_index = i;
                max_quality = pq.top();
                min_cost = total_quality * current_k;
            }
        }
    }

    vector<people> data_temp;
    data_temp.assign(data_store.begin(), data_store.begin() + max_index+ 1);
    sort(data_temp.begin(), data_temp.end(), compare2);

    cout << max_worker_num << "\n";

    for(int i = 0; i < max_worker_num; i++){
        cout << data_temp[i].num << "\n";
    }

    return 0;
}