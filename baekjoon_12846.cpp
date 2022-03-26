#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int seg[400000];
ll height[100001];
const int INF = 2000000000;
int n;

int update(int node, int start, int end, int index, int value){
    if(index < start || end < index) return 0;
    if(start == end) return seg[node] = index;
    int mid = (start + end) >> 1;
    int total_min_index;
    int left_min_index = update(node * 2, start, mid, index, value);
    int right_min_index = update(node * 2 + 1, mid + 1, end, index, value);
    if(height[left_min_index] < height[right_min_index]) total_min_index = left_min_index;
    else total_min_index = right_min_index;

    if(height[total_min_index] < height[seg[node]]) return seg[node] = total_min_index;
    else return seg[node];
}

ll ret = -1;
int query(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right){
        return seg[node];
    }
    int mid = (start + end) >> 1;
    int left_min_index = query(node * 2, start, mid, left, right);
    int right_min_index = query(node * 2 + 1, mid + 1, end, left, right);
    if(height[left_min_index] < height[right_min_index]) return left_min_index;
    else return right_min_index;
}

void solution(int left, int right){
    if(right < left) return;
    int min_height_index = query(1, 1, n, left, right);
    if(left == right){
        ret = max(ret, height[min_height_index] * 1LL);
        return;
    }
    else ret = max(ret, height[min_height_index] * (right - left + 1));
    solution(left, min_height_index - 1);
    solution(min_height_index + 1, right);
}

int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    height[0] = INF;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> height[i];
        update(1, 1, n, i, height[i]);
    }

    solution(1, n);
    cout << ret << "\n";
    return 0;   
}