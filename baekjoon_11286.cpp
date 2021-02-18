#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

struct compare{
    bool operator()(const int temp1, const int temp2){
        if(abs(temp1) == abs(temp2)){
            return temp1 > temp2;
        }
        else return abs(temp1) > abs(temp2);
    }
};

int main(void){
    fastio;
    priority_queue<int, vector<int>, compare> pq;
    int cal_num;

    cin >> cal_num;

    for(int i = 0; i < cal_num; i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(pq.size() == 0){
                cout << 0 << "\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
        else{
            pq.push(temp);

        }
    }
    return 0;
}