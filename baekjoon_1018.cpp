#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int y, x;
    cin >> y >> x;

    // Store the data
    
    string store[y];
    for(int i = 0; i < y; i++){
        cin >> store[i]; 
    }

    int check_value_store = 64;
    int check_value = 0;

    // Repeat calculating

    for(int y_start = 0; y_start <= y - 8; y_start++){
        for(int x_start = 0; x_start <= x - 8; x_start++){
              for(int i = y_start; i < y_start + 8; i++ ){
                  for(int j = x_start; j < x_start + 8; j++){
                      int check_dicision = (i % 2 + j % 2) % 2;
                      if (check_dicision == 0 & store[i][j] != 'W'){ // 0은 화이트 1은 블랙
                          check_value += 1;
                      }
                      else if(check_dicision == 1 & store[i][j] != 'B'){
                          check_value += 1;
                      }

                  }
              }
              
              if (64 - check_value < check_value){
                  check_value = 64 - check_value;
              }
              if (check_value < check_value_store){
                  check_value_store = check_value;
              }
              
              check_value = 0; //Return initial value

        }
    }

    // Print result

    cout << check_value_store << "\n";
    
    return 0;
}

