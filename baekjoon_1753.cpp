#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
const int INF = 987654321;
int v, e;
vector<int> dist;
vector<vector<pii>> edge;
bool visited[20000];

int main(void)
{
    fastio;
    memset(visited, 0, sizeof(visited));
    cin >> v >> e;

    edge = vector<vector<pii>>(v);
    dist = vector<int>(v);
    fill(dist.begin(), dist.end(), INF);

    int start;
    cin >> start;
    start--;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back(make_pair(b - 1, c));
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty())
    {
        int cur = -1;
        while (true)
        {
            if (!pq.empty())
            {
                if (!visited[pq.top().second])
                {
                    cur = pq.top().second;
                    pq.pop();
                    break;
                }
                pq.pop();
            }
            else
                break;
        }
        if (cur == -1)
            break;
        visited[cur] = 1; // 방문처리

        for (auto &p : edge[cur])
        {
            int next = p.first, d = p.second;
            if (dist[cur] + d < dist[next])
            {
                dist[next] = dist[cur] + d;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}