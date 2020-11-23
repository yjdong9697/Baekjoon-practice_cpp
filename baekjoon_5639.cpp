#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

void down_cycle(const vector<int> &upper_cycle, int check, int start, int end){
    int end_point = -1;
    if(start >= end){
        return;
    }
    for(int i = start; i < end; i++){
        if(upper_cycle[check] < upper_cycle[i]){
            end_point = i;
            break;
        }
    }
    if(end_point != -1){
        down_cycle(upper_cycle, check + 1, check + 1, end_point);
        down_cycle(upper_cycle, end_point, end_point, end);
        cout << upper_cycle[check] << "\n";
    }
    else{
        down_cycle(upper_cycle, check + 1, check + 1, end); 
        cout << upper_cycle[check] << "\n";
    }
    return;   
}

int main(void){
    vector<int> upper_cycle;

    int temp;
    while(true){
        cin >> temp;
        if(cin.eof() == true) break;
        else upper_cycle.push_back(temp);   
    }// data_store until EOF
    down_cycle(upper_cycle, 0, 0, upper_cycle.size());
    return 0;
}