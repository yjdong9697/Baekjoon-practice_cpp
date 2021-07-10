#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    string s;
    cin >> s;

    string min = " ";
    for(int i = 0; i < s.size() - 1; i++){
        for(int j = i + 1; j < s.size() - 1; j++){
            string t = s;
            reverse(t.begin(), t.begin() + i + 1);
            reverse(t.begin() + i + 1, t.begin() + j + 1);
            reverse(t.begin() + j + 1, t.end());

            if(min == " ") min = t;
            else{
                if(t < min) min = t;
            }
        }
    }

    cout << min << "\n";
    return 0;
}