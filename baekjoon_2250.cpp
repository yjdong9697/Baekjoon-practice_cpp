#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
class tree{
    public:
    int left;
    int right;
    tree() : left(-1), right(-1)
    {}
    tree(int x, int y) : left(x), right(y)
    {}
};

tree r[10001];
int parent[10001];
int width_value = 1;;
vector<vector<int> > s(10001);

void dfs(int x, int height){
    tree cur = r[x];
    if(cur.left != -1){
        dfs(cur.left, height + 1);
    }
    s[height].push_back(width_value++);
    if(cur.right != -1){
        dfs(cur.right, height + 1);
    }
    return;
}


int main(void){
    fastio;
    memset(parent, -1, sizeof(parent));
    int n;
    cin >> n;

    int leaf_node;
    int root_node;

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(b == -1 && c== -1) leaf_node = a;
        parent[b] = a;
        parent[c] = a;
        r[a] = tree(b, c);
    }

    // Find root node

    root_node = leaf_node;

    while(true){
        if(parent[root_node] != -1){
            root_node = parent[root_node];
        }
        else break;
    }

    dfs(root_node, 1);

    int max_value = -1;
    int max_index;


    for(int i = 1; i <= 10000; i++){
        if(s[i].empty()) continue;
        else{
            int cur_width = *(s[i].end() - 1) - s[i][0] + 1;
            if(cur_width > max_value){
                max_value = cur_width;
                max_index = i;
            }
        }
    }
    cout << max_index << " " << max_value << "\n";
    return 0;
}