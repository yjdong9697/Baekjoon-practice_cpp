#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
vector<int> v;
int N, M;
int result[8];

void solve(int cur, int index)
{
    result[index++] = v[cur];
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            if (i != M - 1)
                cout << result[i] << " ";
            else
                cout << result[i] << "\n";
        }
        return;
    }
    for (int i = 0; i < N; i++)
    {
        solve(i, index);
    }
    return;
}

int main(void)
{
    fastio;
    memset(result, 0, sizeof(result));
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        solve(i, 0);
    }
    return 0;
}