#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string check_value;
    cin >> check_value; // first start

    while (check_value != "0"){
        int size_of_int = check_value.size();
        int half_value = size_of_int / 2;
        bool paneldrom_check = true;

        for(int i = 0; i < half_value; i++){
            if (check_value[i] != check_value[size_of_int - i - 1]){
                paneldrom_check = false;
                cout << "no\n";
                break; 
            }    
        }
        
        if (paneldrom_check == true){
            cout << "yes\n";
        }
        cin >> check_value;
    }
    return 0;
}