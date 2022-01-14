#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
    fastio;
    vector<int> v(9);
    int total_sum = 0;
    for(int i = 0; i < 9; i++){
        cin >> v[i];
        total_sum += v[i];
    }
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(total_sum - (v[i] + v[j]) == 100){
                v.erase(v.begin() + i);
                v.erase(v.begin() + j - 1);
                sort(v.begin(), v.end());
                for(auto &p : v){
                    cout << p << "\n";
                }
                return 0;
            } 
        }
    }   
}