#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int how_many_repeat;

    cin >> how_many_repeat;

    string checker;
    string non_pass_element;

    int count = 0; // how many group element in this group 

    for(int i = 0; i < how_many_repeat; i++){

        cin >> checker;
        int len_of_string = checker.size(); // input string and check len
        char past_element = checker[0];
        bool final_check = true;

        for(int j = 0; j < len_of_string; j++){ //check all string element
            
            if (j == 0) {
                non_pass_element = checker[j]; // start element setting
            }

            else if(checker[j] != past_element){

                char check_element = checker[j]; // element 
                int len_checker = non_pass_element.size(); // compare values

                bool group_element_check = true; // default boolean flag
                
                for(int k = 0; k < len_checker; k++){ // compare values by iteration

                    if(non_pass_element[k] == check_element){
                        group_element_check = false;
                    } 
                }

                if(group_element_check == false){

                    final_check = false;

                    break; // not group word
                }

                else {
                    non_pass_element += checker[j];
                    past_element = checker[j];
                }
            }

        }

        if (final_check == true) count += 1;

        checker.clear();
        non_pass_element.clear();

    }

    cout << count << "\n";

    return 0;

}