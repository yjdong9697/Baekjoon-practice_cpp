#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n; // Input data

    int len_check = n;
    int len_count = 0;

    while(len_check != 0){
        len_check /= 10;
        len_count += 1;
    }

    int complete = 0;
    int result_data = 0;

    for(int i = 1; i < len_count; i++){
        int cal_data = pow(10, i) - complete - 1;
        result_data += cal_data * i;
        complete += cal_data;
    }

    result_data += (n - complete) * (len_count);

    cout << result_data << "\n";

    return 0;
}