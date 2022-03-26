#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int seg[400000];
ll seg_1[400000];
ll height[100001];
const int INF = 2000000000;
int n;

void update_1(int node, int start, int end, int index, int value){
    if(index < start || end < index) return;
    if(start == end){
        seg_1[node] += value;
        return;
    }
    seg_1[node] += value;
    int mid = (start + end) >> 1;
    update_1(node * 2, start, mid, index, value);
    update_1(node * 2 + 1, mid + 1, end, index, value);
}

ll query_1(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg_1[node];
    int mid = (start + end) >> 1;
    return query_1(node * 2, start, mid, left, right) + query_1(node * 2 + 1, mid + 1, end, left, right);
}



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

ll ret = -1;
int r_l;
int r_r;
void solution(int left, int right){
    if(right < left) return;
    int min_height_index = query(1, 1, n, left, right);
    if(ret < height[min_height_index] * query_1(1, 1, n, left, right)){
        r_l = left;
        r_r = right;
        ret = height[min_height_index] * query_1(1, 1, n, left, right);
    }
    solution(left, min_height_index - 1);
    solution(min_height_index + 1, right);
}

int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    memset(seg_1, 0, sizeof(seg_1));
    height[0] = INF;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> height[i];
        update(1, 1, n, i, height[i]);
        update_1(1, 1, n, i, height[i]);
    }

    solution(1, n);
    cout << ret << "\n";
    cout << r_l << " " << r_r << "\n";
    return 0;   
}