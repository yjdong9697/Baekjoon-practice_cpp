#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){

    int repeat_value;
    cin >> repeat_value;
    int group_string_count = 0; // count group string

    for (int i = 0; i < repeat_value; i++){
        string check_string;
        cin >> check_string; // input string
        bool if_string_group = true;
        
        int alphabet[123] = {0}; // Initial setting (alphabet count)
        int len_string = check_string.size();
        char before_char = '0';

        for (int j = 0; j < len_string; j++){
            
            int check_char = check_string[j];
            if (check_char == before_char){
                continue;
            }
            else{
                if (alphabet[check_char] == 0){
                    alphabet[check_char] += 1;
                }
                else{
                    if_string_group = false;
                    break;
                }

                before_char = check_char; // Reinitialize before_char
            }

        }

        if (if_string_group == true) group_string_count += 1;
    }

    cout << group_string_count << "\n";
    return 0;

}