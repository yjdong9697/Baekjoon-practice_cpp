#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
map<int, int> cap;
int result[8];
vector<int> s;
vector<vector<int> > output;
int n, m;

void solve(int index, int cur)
{
    result[cur++] = s[index];
    cap[s[index]] -= 1;
    if (cur == m)
    {
        vector<int> temp;
        for (int i = 0; i < m; i++)
        {
            temp.push_back(result[i]);
        }
        output.push_back(temp);
    }
    else
    {
        for (int i = index; i < s.size(); i++)
        {
            if (cap[s[i]] > 0)
            {
                solve(i, cur);
            }
        }
    }
    cap[s[index]] += 1;

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
        cap[t] += 1;
        s.push_back(t);
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end()); // 중복 제거

    for (int i = 0; i < n; i++)
    {
        solve(i, 0);
    }
    sort(output.begin(), output.end());
    output.erase(unique(output.begin(), output.end()), output.end());
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}