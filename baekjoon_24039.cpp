#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n[27] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

int main(void){
    fastio;
    vector<int> v;
    for(int i = 0; i < 26; i++){
        v.push_back(n[i] * n[i + 1]);
    }

    int t;
    cin >> t;
    cout << *upper_bound(v.begin(), v.end(), t) << "\n";
    return 0;
}