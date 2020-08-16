#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;
    int data_list[N];
    for(int i = 0; i < N; i++){
        int value;
        cin >> value;
        data_list[i] = value;
    }
    int min_value = * min_element(data_list, data_list + N);
    int max_value = * max_element(data_list, data_list + N);
    cout << min_value << " "<< max_value << "\n";
    
    return 0;

}