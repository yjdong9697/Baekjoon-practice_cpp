#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0). cin.tie(0), cout.tie(0)

using namespace std;

vector<int> preorder;
vector<int> inorder;
int index_val;

void find(int left, int right){
    
    int cur = preorder[index_val++];
    int index;

    if (left == right)
    {
        cout << cur << " ";
        return;
    }
    else if(left > right){
        index_val--;
        return;
    }

    for(int i = left; i <= right; i++){
        if(inorder[i] == cur){
            index = i;
            break;
        }
    }

    find(left, index - 1);
    find(index + 1, right);
    cout << cur << " ";
    return;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        index_val = 0;
        int n;
        cin >> n;
        preorder = vector<int>(n);
        inorder = vector<int>(n);

        for(int i = 0 ; i < n; i++){
            cin >> preorder[i];
        }

        for(int i = 0; i < n; i++){
            cin >> inorder[i];
        }

        find(0, n - 1);
        cout << "\n";
    }
    return 0;
}