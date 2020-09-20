#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    queue<int> circular_data;
    vector<int> result_data;
    for(int i = 0; i < n; i++){
        circular_data.push(i + 1);
    } // Setting circular_data

    // 1개 남을때까지 k를 기준으로 계속 pop하고 push해서 뒤로 보내는 작업을 반복

    while(circular_data.size() != 0){
        for(int i = 0; i < k - 1; i++){
            int temp = circular_data.front();
            circular_data.pop();
            circular_data.push(temp);
        }

        result_data.push_back(circular_data.front());
        circular_data.pop();
    }

    // 결과 출력

    cout << "<";

    for(int i = 0; i < n - 1; i++){
        cout << result_data[i] << ", ";
    }
    cout << result_data[n - 1] << ">\n";

    return 0;
}