#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> compare_store(N, 0);

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        compare_store[i] = temp;
    } // Compare data_store

    int count = 0;

    while(true){
        bool check = false;
        bool zero_check = true;
        for(int i = 0; i < N; i++){
            if(compare_store[i] == 1){
                count += 1;
                compare_store[i] = 0;
                zero_check = false;
            }
            else if(compare_store[i] == 0);
            else if(compare_store[i] % 2 == 1){
                count += 1;
                compare_store[i] -= 1;
                compare_store[i] /= 2;
                zero_check = false;
                check = true;
            }
            else{
                compare_store[i] /= 2;
                zero_check = false;
                check = true;       
            }
        }
        if(check == true){
            count += 1;
        }
        if(zero_check == true) break;
    }

    cout << count << "\n";
    return 0;
}