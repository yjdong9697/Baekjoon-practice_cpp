#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> card(20000001, 0);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        temp += 10000000;
        card[temp] += 1;
    } //data sort

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        temp += 10000000;
        cout << card[temp] << " ";
    }

    cout << "\n";
    return 0;
}