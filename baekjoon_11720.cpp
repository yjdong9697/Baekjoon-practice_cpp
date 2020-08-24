#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int string_length;
    cin >> string_length;

    string data;
    cin >> data;
    int sum = 0;
    for(int i = 0; i < string_length; i++){
        sum += int(data[i] - '0');
    }

    cout << sum << "\n";

    return 0;

}