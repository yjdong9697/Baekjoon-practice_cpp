#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    while(true){
        int n;
        cin >> n;
        vector<int> data;
        if(n == 0) break;
        else{
            int zero_count = 0;
            for(int i = 0; i < n; i++){
                int temp;
                cin >> temp;
                if(temp == 0) zero_count++;
                else data.push_back(temp);
            }
            sort(data.begin(), data.end());

            vector<int> first;
            vector<int> second;
            int cur_index = 2;
            
            first.push_back(data[0]);
            second.push_back(data[1]);

            while(zero_count > 0){
                first.push_back(0);
                zero_count -= 1;
                if(zero_count > 0){
                    second.push_back(0);
                    zero_count -= 1;
                }
                else{
                    if(cur_index < data.size()){
                        second.push_back(data[cur_index++]);
                    }
                }
            }

            while(cur_index < data.size()){
                first.push_back(data[cur_index++]);
                if(cur_index < data.size()){
                    second.push_back(data[cur_index++]);
                }
            }

            int result = 0;

            for(int i = 0; i < first.size(); i++){
                result += first[i] * pow(10, first.size() - i - 1);
            }
            for(int j = 0; j < second.size(); j++){
                result += second[j] * pow(10, second.size() - j - 1);
            }

            cout << result << "\n";
        }
    }
    return 0;
}