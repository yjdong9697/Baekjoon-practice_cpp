#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    // pPAp
    int n;
    string s;
    cin >> n >> s;

    int cur = -1;
    int result = 0;

    for(int i = 0; i < s.size(); i++){
        if(cur == -1){
            if(s[i] == 'p') cur = 1;
        }
        else if(cur == 1){
            if (s[i] == 'P') cur++;
            else{
                if(s[i] == 'p') cur = 1;
                else cur = -1;
            }
        }
        else if(cur == 2){
            if (s[i] == 'A') cur++;
            else
            {
                if (s[i] == 'p')
                    cur = 1;
                else
                    cur = -1;
            }
        }
        else if(cur == 3){
            if (s[i] == 'p') cur++;
            else cur = -1;
        }

        if(cur == 4){
            result += 1;
            cur = -1;
        }
    }

    cout << result << "\n";
    return 0;
}