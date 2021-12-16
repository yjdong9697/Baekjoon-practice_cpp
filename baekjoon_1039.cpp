#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int visited[1000001];

int main(void)
{
    fastio;
    memset(visited, -1, sizeof(visited));
    int n, K;
    cin >> n >> K;

    queue<int> q;
    q.push(n);

    int move_num = 0;

    while (move_num < K && !q.empty())
    {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            int cur = q.front();
            string cur_s = to_string(cur);

            q.pop();

            for (int j = 0; j < cur_s.size() - 1; j++)
            {
                for (int k = j + 1; k < cur_s.size(); k++)
                {
                    string next = cur_s;
                    swap(next[j], next[k]);
                    if (next[0] == '0')
                        continue;
                    if (visited[stoi(next)] != move_num)
                    {
                        q.push(stoi(next));
                        visited[stoi(next)] = move_num;
                    }
                }
            }
        }
        move_num++;
    }

    vector<int> result;

    while (!q.empty())
    {
        result.push_back(q.front());
        q.pop();
    }

    if (result.empty())
    {
        cout << -1 << "\n";
        return 0;
    }

    sort(result.begin(), result.end());

    cout << *(result.end() - 1) << "\n";
    return 0;
}