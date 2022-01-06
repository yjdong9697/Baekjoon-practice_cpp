#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

bool visited[101][1 << 14];

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> s;

    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        s[t] = i;
    }

    vector<vector<pii> > v(n + 1);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    queue<pii> q;
    q.push(make_pair(1, 0));
    visited[1][0] = 1;

    int max_num = 0;

    while(!q.empty()){
        int cur = q.front().first;
        int key = q.front().second;
        q.pop();
        if(cur == 1){
            if (s.find(cur) != s.end()){
                max_num = max(max_num, __builtin_popcount(key | (1 << s[cur])));
            }
            else max_num = max(max_num, __builtin_popcount(key));
        }
        for (int i = 0; i < v[cur].size(); i++)
        {
            int to = v[cur][i].first;
            int limit = v[cur][i].second;
            if(s.find(cur) != s.end()){
                if(__builtin_popcount(key | (1 << s[cur])) <= limit && !visited[to][key | (1 << s[cur])]){
                    q.push(make_pair(to, key | (1 << s[cur])));
                    visited[to][key | (1 << s[cur])] = 1;
                }
            }
            if (__builtin_popcount(key) <= limit && !visited[to][key]){
                q.push(make_pair(to, key));
                visited[to][key] = 1;
            }
        }
    }

    cout << max_num << "\n";
    return 0;
}