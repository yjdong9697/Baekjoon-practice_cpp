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
    string s;
    cin.clear();
    getline(cin, s);
    cin >> s;
    int a = s[0] - '0';
    int b = s[4] - '0';
    int c = s[8] - '0';
    if(c == a + b){
        cout << "YES\n";
    }
    else cout << "NO\n";
    return 0;
}