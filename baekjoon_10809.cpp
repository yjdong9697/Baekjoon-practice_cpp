#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string input_data;
    cin >> input_data;

    int size_of_string = input_data.size();
    
    // Setting alphabet(Default value is -1)
    int alpha_len = 'z' - 'a';
    int alpha[alpha_len + 1];
    fill_n(alpha, alpha_len + 1, -1);

    // Fill the value
    
    for(int i = 0; i < size_of_string; i++){
        int value = input_data[i] - 'a';
        if (alpha[value] == -1){
            alpha[value] = i;
        }
    }

    // Print the value

    for(int i = 0; i < alpha_len + 1; i++){
        cout << alpha[i] << " ";
    }
    cout << "\n";

    return 0;


}