#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int result[8];
vector<int> s;
int n, m;

void solve(int index, int cur)
{
    result[cur++] = s[index];
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            if (i != m - 1)
                cout << result[i] << " ";
            else
                cout << result[i] << "\n";
        }
        return;
    }
    else
    {
        for (int i = index; i < s.size(); i++)
            solve(i, cur);
    }
    return;
}

int main(void)
{
    fastio;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s.push_back(t);
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end()); // 중복 제거

    for (int i = 0; i < s.size(); i++)
    {
        solve(i, 0);
    }
    return 0;
}