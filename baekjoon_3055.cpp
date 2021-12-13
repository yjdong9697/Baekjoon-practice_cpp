#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int r[50][50];
bool visited[50][50];

int main(void)
{
    memset(visited, 0, sizeof(visited));
    int n, m;
    cin >> n >> m;
    queue<pii> pos;
    queue<pii> fire_pos;
    pii end_pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char t;
            cin >> t;
            if (t == '.')
            {
                r[i][j] = 1;
            }
            else if (t == 'X')
            {
                r[i][j] = 2;
            }
            else if (t == 'S')
            {
                r[i][j] = 3;
                pos.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            else if(t == '*')
            {
                r[i][j] = 4;
                fire_pos.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            else end_pos = make_pair(i, j);
        }
    }

    int move = 1;
    int flag = false;
    int imp_flag = false;
    while (true)
    {
        int human_q_size = pos.size();
        int fire_q_size = fire_pos.size();

        if (human_q_size == 0)
        {
            imp_flag = true;
            break;
        }

        for (int i = 0; i < human_q_size; i++)
        {
            int x = pos.front().first;
            int y = pos.front().second;
            pos.pop();
            if (r[x][y] != 3)
                continue;
            for (int j = 0; j < 4; j++)
            {
                int dx = x + move_x[j];
                int dy = y + move_y[j];
                if(make_pair(dx, dy) == end_pos){
                    flag = true;
                    break;
                }
                if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                else
                {
                    if (!visited[dx][dy] && r[dx][dy] == 1)
                    {
                        pos.push(make_pair(dx, dy));
                        visited[dx][dy] = 1;
                        r[dx][dy] = 3;
                    }
                }
            }
        }
        if (flag == true || imp_flag == true)
            break;

        for (int i = 0; i < fire_q_size; i++)
        {
            int x = fire_pos.front().first;
            int y = fire_pos.front().second;
            fire_pos.pop();
            for (int j = 0; j < 4; j++)
            {
                int dx = x + move_x[j];
                int dy = y + move_y[j];
                if (dx < 0 || dx >= n || dy < 0 || dy >= m)
                    continue;
                else
                {
                    if (r[dx][dy] == 1 || r[dx][dy] == 3)
                    {
                        fire_pos.push(make_pair(dx, dy));
                        visited[dx][dy] = 1;
                        r[dx][dy] = 4;
                    }
                }
            }
        }
        move++;
    }
    if (imp_flag)
    {
        cout << "KAKTUS\n";
    }
    else
        cout << move << "\n";
    return 0;
}