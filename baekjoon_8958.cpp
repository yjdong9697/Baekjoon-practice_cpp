#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    
    // How many repetition
    int N;
    cin >> N;
    int result[N];

    for(int i = 0; i < N; i++){
        string test_case;
        cin >> test_case;
        int check = 0;
        int sum = 0;
        
        for(int i = 0; i < test_case.size(); i++){

            if (test_case[i] == 'O'){
                check += 1;
            }
            else{
                sum += (check * (check + 1)) / 2;
                check = 0;
            }
        }
        sum += (check * (check + 1)) / 2;
        result[i] = sum;
    }
    
    for(int i = 0; i < N; i++){
        cout << result[i] << "\n";
    }

    return 0;

}