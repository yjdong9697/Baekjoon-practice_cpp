#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

class point
{
public:
    int z;
    int x;
    int y;
    point() {}
    point(int a, int b, int c)
    {
        z = a;
        x = b;
        y = c;
    }
};

int r[100][100][100];
bool visited[100][100][100];
int n, m, l;
int move_z[6] = {0, 0, 0, 0, 1, -1};
int move_x[6] = {-1, 1, 0, 0, 0, 0};
int move_y[6] = {0, 0, -1, 1, 0, 0};

int main(void)
{
    fastio;
    memset(visited, 0, sizeof(visited));
    cin >> l >> m >> n;
    queue<point> q;
    int tomato_num = 0;
    if (n == 0 && m == 0 && l == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < l; k++)
            {
                int t;
                cin >> t;
                r[i][j][k] = t;

                if (t == 1)
                {
                    q.push(point(i, j, k));
                    visited[i][j][k] = 1;
                }
                else if(t == 0) tomato_num++;
            }
        }
    }

    int move_num = 0;
    int flag = false;

    while (!q.empty())
    {
        int q_size = q.size();
        if (tomato_num == 0)
        {
            flag = true;
            break;
        }
        for (int i = 0; i < q_size; i++)
        {
            point cur = q.front();
            q.pop();
            int z = cur.z;
            int x = cur.x;
            int y = cur.y;
            for (int j = 0; j < 6; j++)
            {
                int dz = z + move_z[j];
                int dx = x + move_x[j];
                int dy = y + move_y[j];
                if (dz < 0 || dz >= n || dx < 0 || dx >= m | dy < 0 || dy >= l)
                    continue;
                else
                {
                    if (!visited[dz][dx][dy] && r[dz][dx][dy] == 0)
                    {
                        q.push(point(dz, dx, dy));
                        visited[dz][dx][dy] = 1;
                        tomato_num--;
                    }
                }
            }
        }
        if (flag)
            break;
        move_num++;
    }

    if (!flag)
    {
        cout << "-1\n";
    }
    else
        cout << move_num << "\n";

    return 0;
}