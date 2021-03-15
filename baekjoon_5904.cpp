#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n;
vector<int> dp;

void find_value(int num, int n){
    if(n == 0){
        if(num == 1){
            cout << "m\n";
            return;
        }
        else{
            cout << "o\n";
            return;
        }
    }
    if(num <= dp[n - 1]){
        find_value(num, n - 1);

    }
    else if(dp[n - 1] < num && num <= dp[n - 1] + n + 2){
        if(num - dp[n - 1] == 1){
            cout << "m\n";
            return;
        }
        else{
            cout << "o\n";
            return;
        }

    }
    else{
        find_value(num - dp[n - 1] - n - 3, n - 1);
    }
}

int main(void){
    cin >> n;
    dp.push_back(3);
    int count = 1;
    while(true){
        int add_value =  count + 3;
        int increase_value = dp[count - 1] * 2 + add_value;
        dp.push_back(increase_value);
        count++;
        if(increase_value >= n) break;
    }
    find_value(n, dp.size() - 1);
}