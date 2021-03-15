#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n;
vector<string> data_value;

string checker(int size, int x, int y){
    if(size == 1){
        if(data_value[x][y] == '0') return "0"; // white
        else return "1"; // black
    }
    else{
        string left_up = checker(size / 2, x, y);
        string right_up = checker(size / 2, x, y + (size / 2));
        string left_down = checker(size / 2, x + (size / 2), y); 
        string right_down = checker(size / 2, x + (size / 2), y + (size / 2));

        if(left_up == left_down && right_up == right_down && left_up == right_up){
            if(left_up == "0"){
                return "0";
            }
            else if(left_up == "1"){
                return "1";
            }
        }
        return "(" + left_up + right_up + left_down + right_down + ")";
    }
}

int main(void){
    fastio;
    cin >> n;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        data_value.push_back(temp);   
    }

    cout << checker(n, 0, 0) << "\n";
    return 0;
}