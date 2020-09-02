#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int data_store[n][2];

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y; // input value

        data_store[i][0] = x;
        data_store[i][1] = y;
    }

    int compare[n];
    fill_n(compare, n, 0);

    for (int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
            if (i == j) continue;
            
            else{
                if(data_store[i][0] < data_store[j][0] && data_store[i][1] < data_store[j][1]){
                    compare[i] += 1;
                }

            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << compare[i] + 1 << " ";
    }
    cout <<"\n";
    return 0;
}