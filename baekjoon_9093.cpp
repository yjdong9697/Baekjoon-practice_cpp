#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    cin.ignore(); // Erase \n
    
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int begin = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin() + begin, s.begin() + i);
                begin = i + 1;
            }
        }
        reverse(s.begin() + begin, s.end());
        cout << s << "\n";
    }
    return 0;
}