#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        long long n;
        cin >> n;
        string s;
        cin >> s;
        vector<long long> bin;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                bin.push_back(i);
            }
        }

        long long result = bin[0] * (bin[0] + 1) / 2 + (n - bin[bin.size() - 1] - 1) * (n - bin[bin.size() - 1]) / 2;

        for(int i = 0; i < bin.size() - 1; i++){
            long long front = bin[i];
            long long back = bin[i + 1];
            long long v = (back - front) / 2;
            if((back - front) % 2 == 1){
                result += v * (v + 1);
            }
            else{
                result += v * v;
            }
        }
        cout << "Case #" << i << ": " << result << "\n";
    }
    return 0;
}