#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> data_store;

    long long sum = 0;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        sum += temp;
        data_store.push_back(temp);
    }
    sort(data_store.begin(), data_store.end());

    double check_num = floor((double) sum / n + 0.5);

    cout << check_num << "\n"; //first mean value;
    
    cout << data_store[n / 2] << "\n"; // second mean value;
    
    int occurence_num = 1;
    int max_store = -4001;
    int occurence_num_store = data_store[0];
    int count = 0;
    int result_store = data_store[0];
    for(int i = 1; i < n; i++){
        if(occurence_num_store == data_store[i]){
            occurence_num += 1;
        }
        else{
            if(max_store < occurence_num){
                count = 0;
                max_store = occurence_num;
                occurence_num_store = data_store[i];
                occurence_num = 1;
                result_store = data_store[i - 1];
            }
            else if(max_store == occurence_num){
                if(count == 0){
                    occurence_num_store = data_store[i];
                    count += 1;
                    result_store = data_store[i - 1];
                    occurence_num = 1;
                }
                else{
                    count += 1;
                    occurence_num = 1;
                    occurence_num_store = data_store[i];
                }
            }
            else{
                occurence_num_store= data_store[i];
                occurence_num = 1;
            }

        }
    }
    if(max_store < occurence_num){
        result_store = data_store[n - 1];
    }
    else if(max_store == occurence_num){
        if(count == 0){
            result_store = data_store[n - 1];
        }
    }

    cout << result_store << "\n";

    cout << data_store[n - 1] - data_store[0] << "\n"; // fourth mean value;
}