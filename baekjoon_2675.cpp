#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int how_many_repeat;
    cin >> how_many_repeat;
    string string_store[how_many_repeat];

    for(int i = 0; i < how_many_repeat; i++){
        int repeat_value;
        string input_string;
        cin >> repeat_value >> input_string;
        int size_of_string = input_string.size();
        
        for(int n = 0; n < size_of_string; n++){
            for(int j = 0; j < repeat_value; j++){
                string_store[i] += input_string[n];
            }
            
        }
        
    }

    for(int i = 0; i < how_many_repeat; i++){
        cout << string_store[i] << "\n";
    }
    
    return 0;
}