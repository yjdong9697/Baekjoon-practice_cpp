#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
bool visited[100001];

class tree{
    public:
    int l;
    int r;
    tree() : l(-1), r(-1)
    {}
    tree(int a, int b) : l(a), r(b)
    {}
};

vector<tree> r;
int n;

int dfs(int x){
    visited[x] = 1;
    int component_num = 0;
    
    if(r[x].l != -1 && !visited[r[x].l]){
        component_num += dfs(r[x].l);
    }
    if (r[x].r != -1 && !visited[r[x].r])
    {
        component_num += dfs(r[x].r);
    }
    return component_num + 1;
}

int main(void){
    fastio;
    cin >> n;
    r = vector<tree> (n + 1);

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        r[a] = tree(b, c);
    }

    int component_num = dfs(1);

    tree current_node = r[1];
    int erase_count = 0;

    while(true){
        int next = current_node.r;
        if(next != -1){
            current_node = r[next];
            erase_count++;
        }
        else break;
    }

    cout << (component_num - 1) * 2 - erase_count << "\n";
    return 0;
}