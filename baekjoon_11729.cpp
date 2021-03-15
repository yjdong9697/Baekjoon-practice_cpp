#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
vector<pii> route;

void hanoi(int n, int from, int by, int to){
    // Base case
    if(n == 1) route.push_back(make_pair(from, to));
    else{
        hanoi(n - 1, from, to, by);
        route.push_back(make_pair(from, to));
        hanoi(n - 1, by, from, to);
    }
}

int main(void){
    fastio;
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << route.size() << "\n";
    for(int i = 0; i < route.size(); i++){
        cout << route[i].first << " " << route[i].second << "\n";
    }
    return 0;
}