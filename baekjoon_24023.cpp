#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

ll seg[800004];
int n, k;

ll update(int node_index, int node_left, int node_right, int index, int value)
{
    if (index < node_left || node_right < index) return seg[node_index]; // Out of bound 
    if(node_left == node_right){ 
        return seg[node_index] = value;
    } 
    else{
        int mid = (node_left + node_right) / 2;
        return seg[node_index] = update(node_index * 2, node_left, mid, index, value) |
        update(node_index * 2 + 1, mid + 1, node_right, index, value);
    } 
}

ll query(int node_index, int node_left, int node_right, int query_left, int query_right)
{
    if (query_right < node_left || node_right < query_left) return 0LL;
    else if (query_left <= node_left && node_right <= query_right) return seg[node_index];
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right) | query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        update(1, 1, n, i, t);
    }

    for(int i = 1; i <= n; i++){
        int start = i - 1;
        int end = n;
        while(start + 1 < end){
            int mid = (start + end) / 2;
            if (query(1, 1, n, i, mid) >= k) end = mid;
            else start = mid;
        }
        if (query(1, 1, n, i, end) == k)
        {
            cout << i << " " << end;
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}