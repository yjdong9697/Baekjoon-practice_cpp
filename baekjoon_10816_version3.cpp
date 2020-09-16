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

    vector<int> card;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        card.push_back(temp);
    } //data sort

    sort(card.begin(), card.end());

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        int upper, lower;
        upper = upper_bound(card.begin(),card.end(),temp) - card.begin();
        lower = lower_bound(card.begin(),card.end(),temp) - card.begin();
        cout << upper - lower << " ";
    }

    cout << "\n";
    return 0;
}