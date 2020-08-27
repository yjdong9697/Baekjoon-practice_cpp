#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    string input_data;
    getline(cin, input_data, '\n'); // string store containing blank
    
    int size_of_string = input_data.size();

    bool blank_check = true; // Count with considering blank status
    int count = 0;
    
    for(int i = 0; i < size_of_string; i++){

        if (input_data[i] == ' '){
            blank_check = true; // Blank state change
        }

        else{
            if(blank_check == true){
                count += 1; 
            }

            blank_check = false;
            
        }
    }

    cout << count << "\n";

    return 0;
}