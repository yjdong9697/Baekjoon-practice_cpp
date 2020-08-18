#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int a, b ,c, result;
    string result_string;
    
    // Store num

    int num_store[10];
    fill_n(num_store, 10, 0);
    
    
    // Input data 
    
    cin >> a;
    cin >> b;
    cin >> c;

    result = a * b * c;
    result_string = to_string(result);

    int len_of_result = result_string.length();
    
    for(int i = 0; i < len_of_result; i++){
        int value = result_string[i] - '0';
        num_store[value] += 1;
    }

    for(int i = 0; i < 10; i++){
        cout << num_store[i] <<"\n";
    }
}