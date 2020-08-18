#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    cin >> num;

    int data[num];

    for(int i = 0; i < num; i++){
        int value;
        cin >> value;
        data[i] = value;
    }

    int max_value = * max_element(data, data + num);
    
    long double sum_of_data = 0;

    for(int i = 0; i < num; i++){
        sum_of_data += (long double)data[i] / max_value * 100;
    }

    long double return_value = sum_of_data / num;

    cout << fixed;
    cout.precision(4);
    cout << return_value << "\n";
    return 0;

}