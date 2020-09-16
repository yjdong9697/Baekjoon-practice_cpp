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
    } // store data

    sort(card.begin(), card.end()); // sorting data

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int check_value;
        cin >> check_value;
        int start = 0;
        int end = n;
        int mid = -1;
        int min, max;

        // Upper bound
        while (start < end){
            mid = (start + end) / 2;
            if(card[mid] <= check_value){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }

        max = start;

        start = 0;
        end = n;

        // Lower bound
        while (start < end){
            mid = (start + end) / 2;
            if(card[mid] < check_value){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        min = start;

        cout << max - min<< " ";
    }
    
    cout << "\n";

    return 0;

}