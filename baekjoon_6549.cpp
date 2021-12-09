#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void)
{
    fastio;
    long long v[100002];
    while (true)
    {
        memset(v, 0, sizeof(v));
        int n;
        stack<long long> s;
        cin >> n;
        if (n == 0)
            return 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        s.push(0);
        long long max_value = 0;

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
                        long long cmp = s.top();
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
    }

    return 0;
}