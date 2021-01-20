#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int max_start; // 가장 긴 것의 시작
int max_end; //  가징 긴 것의 종료
int max_length = -1; // 가장 긴 것의 길이

struct bus{
    int start;
    int end;
    int index_num;
    bus(int temp1, int temp2, int temp3);
};

bus::bus(int temp1, int temp2, int temp3){
    start = temp1;
    end = temp2;
    index_num = temp3 + 1;
}

// Bus vector를 시작시작이 제일 빠르게끔 세팅
bool compare(const bus &data1, const bus &data2){
    if(data1.start == data2.start){
        if(data1.start > data1.end && data2.start < data2.end){
            return true;
        }
        else if(data1.start < data1.end && data2.start > data2.end){
            return false;
        }
        else return data1.end > data2.end; // 시작 지점이 같으면 끝지점이 더 뒤인거를 먼저 체크해서 지워지게끔
    }
    else{
        return data1.start < data2.start; // 기본적으로는 시작지점이 빠른 것이 앞에 오게끔
    }
}

int length_check(int start, int end){
    if(end < start) return N - (start - end);
    return end - start;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    vector<bus> data_store;

    for(int i = 0; i < M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if(length_check(temp1, temp2) > max_length){
            max_length = length_check(temp1, temp2);
            max_start = temp1;
            max_end = temp2;
        }
        data_store.push_back(bus(temp1, temp2, i));
    }// 데이터 저장

    for(int i = 0; i < M; i++){
        data_store[i].start = (data_store[i].start + (N - max_start)) % N;
        data_store[i].end = (data_store[i].end + (N - max_start)) % N;
    } // 좌표 보정

    sort(data_store.begin(), data_store.end(), compare); // 시작시간이 제일 빠르게끔 세팅
    vector<int> result_store; // 생존자 모임
    result_store.push_back(data_store[0].index_num);
    int back_store = data_store[0].end;

    for(int i = 1; i < M; i++){
        int compare_num; // 끝 지점 비교기준
        if(data_store[i].end < data_store[i].start){
            compare_num = data_store[i].end + N;
        }
        else compare_num = data_store[i].end;


        if(compare_num > back_store){
            result_store.push_back(data_store[i].index_num);
            back_store = compare_num;
        }
    }

    sort(result_store.begin(), result_store.end());

    for(int i = 0; i < result_store.size(); i++){
        cout << result_store[i] << " ";
    }
    cout << "\n";

    return 0;
}