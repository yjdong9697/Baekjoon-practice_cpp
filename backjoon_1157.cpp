#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    string input_string;
    cin >> input_string;

    int alphabet_setting[100] = {0};
    
    int len_of_string = input_string.size();
    
    for(int i = 0; i < len_of_string; i++){
        int check_char = input_string[i];
        if(check_char > 90) check_char -= 32;
        alphabet_setting[check_char] += 1;
    }

    int max_value = - 1;
    int max_alphabet = - 1;
    bool check = true;

    for(int i = 65; i < 91; i++){
        if (max_value < alphabet_setting[i]){
            check = true;
            max_value = alphabet_setting[i];
            max_alphabet = i;
        }
        else if (max_value == alphabet_setting[i] & alphabet_setting[i] != 0){
            check = false;
        }

    }

    if (check == false){
        cout << "?\n"; //Early exit
        return 0;
    }

    char output_char = max_alphabet;
    cout << output_char << "\n";

    return 0;


}