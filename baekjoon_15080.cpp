#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main() {
    fastio;
    string s, e;
    getline(cin, s);
    getline(cin, e);
    for(int i = 0; i < 2; i++){
        s.replace(s.find(':'), 1, " ");
        e.replace(e.find(':'), 1, " ");
    }

    istringstream st;
    st.str(s);
    int v_1 = 0;
    for(int i = 2; i >= 0; i--){
        string t;
        st >> t;
        v_1 += stoi(t) * pow(60, i);
    }
    istringstream et;
    et.str(e);
    int v_2 = 0;
    for(int i = 2; i >= 0; i--){
        string t;
        et >> t;
        v_2 += stoi(t) * pow(60, i);
    }
    if(v_1 > v_2) cout << 86400 - (v_1 - v_2) << "\n";
    else cout << v_2 - v_1 << "\n";
    return 0;
}