#include <bits/stdc++.h>
#include <numeric>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
vector<int> data_store(200001);

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int gcd_value(int start, int end){
    // Base case
    if(start == end){
        return data_store[start];
    }
    else{
        int mid = (start + end - 1) / 2;
        int l = gcd_value(start, mid);
        int r = gcd_value(mid + 1, end);

        int gcd_l = data_store[start];
        int gcd_r = data_store[mid + 1];
        
        for(int i = start + 1; i <= mid; i++){
            gcd_l = gcd(gcd_l, data_store[i]);
        }

        for(int i = mid + 1; i <= end; i++){
            gcd_r = gcd(gcd_r, data_store[i]);
        }

        return max(gcd_l + r, gcd_r + l);
    }
}

int main(void){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        data_store[i] = t;
    }

    cout << gcd_value(1, n) << "\n";
    return 0;
}