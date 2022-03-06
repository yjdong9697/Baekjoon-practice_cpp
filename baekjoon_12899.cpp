#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int seg[8000000];
void update(int node, int start, int end, int index, int value){
    if(index < start || end < index) return;
    seg[node] += value;
    if(start == end) return;
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, index, value);
    update(node * 2 + 1, mid + 1, end, index, value);
}

int query(int node, int start, int end, int value){
    seg[node]--;
    if(start == end) return start;
    int mid = (start + end) >> 1;
    if(value <= seg[node * 2]) return query(node * 2, start, mid, value);
    else return query(node * 2 + 1, mid + 1, end, value - seg[node * 2]);
}


int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            update(1, 1, 2000000, b, 1);
        }
        else{
            int val = query(1, 1, 2000000, b);
            cout << val << "\n";
        }
    }
    return 0;
}