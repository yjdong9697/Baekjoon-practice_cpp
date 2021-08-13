#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> r(n);
    vector<pair<int, int> > c(n);
    int result[n][n];
    memset(result, 0, sizeof(result));
    
    int r_sum = 0;
    int c_sum = 0;
    
    for(int i = 0; i < n; i++){
        cin >> r[i];
        r_sum += r[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> c[i].first;
        c[i].second = i;
        c_sum += c[i].first;
    }
    
    if(r_sum != c_sum){
        cout << -1 << "\n";
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        int check = r[i];
        sort(c.begin(), c.end(), greater<pair<int, int> >());
        for(int j = 0; j < n; j++){
            if(check == 0) break;
            if(c[j].first > 0){
                check--;
                c[j].first--;
                result[i][c[j].second] = 1;
            }
        }
        if(check > 0){
            cout << -1 << "\n";
            return 0;
        }
    }
    
    cout << 1 << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}