#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0 ; i < n; i++){
        int country, type;
        cin >> country >> type;
        for(int j = 0; j < type; j++){
            int temp1, temp2;
            cin >> temp1 >> temp2;
        }

        cout << country -1 << "\n";
    }

    return 0;

}