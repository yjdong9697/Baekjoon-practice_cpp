#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int t;
    cin >> t;
    // 각 옷 종류 Map을 통해 체크하고 + 1(안 입은 상태 추가) 시킨상태로 multiplication 후에 - 1(다 안 입는 경우 제외)
    for(int i = 0; i < t; i++){
        map<string, int> s;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            string a, b;
            cin >> a >> b;
            s[b] += 1;
        }
        int result = 1;
    
        for(map<string, int>::iterator it = s.begin(); it != s.end(); it++){
            result *= (it -> second + 1);
        }
        cout << result - 1 << "\n";    
    }
    
    return 0;
}