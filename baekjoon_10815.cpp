#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int m;

int binary_sch(int value, const vector<int>& data){
    int start = 0;
    int end = m;
    int mid;

    while(start != end){
        mid = (start + end) / 2;
        if(data[mid] == value){
            return 1;
        }
        else if(data[mid] > value){
            end = mid;
        }
        else start = mid + 1;
    }
    return 0;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m;
    vector<int> card_store;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        card_store.push_back(temp);
    } // Card store;
    sort(card_store.begin(), card_store.end()); // storing data

    int compare_num;
    cin >> compare_num;

    for(int i = 0; i < compare_num - 1; i++){
        int compare_value;
        cin >> compare_value;
        cout << binary_sch(compare_value, card_store) << " ";
    }
    int final_compare;
    cin >> final_compare;
    cout << binary_sch(final_compare, card_store) << "\n";

    return 0;
}