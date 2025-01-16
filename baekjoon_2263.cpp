#include <bits/stdc++.h>

using namespace std;
vector<int> in, post;

void solve(int in_start, int in_end, int post_start, int post_end){
    if(in_start > in_end || post_start > post_end) return;
    int root = post[post_end];
    cout << root << " ";
    int idx;
    for(int i = 0; i <= in_end - in_start; i++){
        if(in[in_start + i] == root){
            idx = i;
            break;
        }
    }
    solve(in_start, in_start + idx - 1, post_start, post_start + idx - 1);
    solve(in_start + idx + 1, in_end, post_start + idx, post_end - 1);
}

int main(void){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        in.push_back(t);
    }

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        post.push_back(t);
    }

    solve(0, n - 1, 0, n - 1);

    return 0;
}