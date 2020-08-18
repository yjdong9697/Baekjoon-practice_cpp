#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    
    // test case num calculate
    
    int test_case_num;
    cin >> test_case_num;

    // Percent store

    double percent_save[test_case_num];

    // Calculate each line

    for(int i = 0; i < test_case_num; i++){
        
        int check_case_num;
        cin >> check_case_num; // how many number in the line

        int check_sum = 0;
        int check_save[1000] = {0};// value save

        for (int j = 0; j <check_case_num; j++){
            int check_value;
            cin >> check_value;
            check_save[j] = check_value; //save it
            check_sum += check_value; // sum
        }

        int data_above_mean = 0; //define mean value 
        double check_mean = (double) check_sum / check_case_num;
        
        for (int j = 0; j < check_case_num; j++){
            if (check_save[j] > check_mean){
                data_above_mean += 1;
            }
        }
        double data_percent = ((double) data_above_mean / check_case_num) * 100 ;
        percent_save[i] = data_percent; // percent save
        

    }
    
    // print percent values

    for(int i = 0; i < test_case_num; i++){
        cout << fixed;
        cout.precision(3);
        cout << percent_save[i];
        cout << "%\n";
    }

    return 0;

}