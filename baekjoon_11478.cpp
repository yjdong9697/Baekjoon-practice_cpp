#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    string s;
    cin >> s;

    set<string> sub_set;

    int size = 1;
    while(size <= s.size()){
        int start = 0;
        int end = size;
        for(; end <= s.size(); start++, end++){
            sub_set.insert(s.substr(start, size));
        }
        size++;
    }

    cout << sub_set.size() << "\n";
    return 0;
}