#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void)
{
    int v[100002];
    memset(v, 0, sizeof(v));
    fastio;
    int n;
    stack<int> s;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    s.push(0);
    int max_value = 0;

    for (int i = 1; i <= n + 1; i++)
    {
        if (v[s.top()] <= v[i])
        {
            s.push(i);
        }
        else
        {
            while (true)
            {
                if (v[s.top()] > v[i])
                {
                    int cmp = s.top();
                    s.pop();
                    max_value = max(max_value, v[cmp] * (i - s.top() - 1));
                }
                else
                    break;
            }
            s.push(i);
        }
    }

    cout << max_value << "\n";
    return 0;
}