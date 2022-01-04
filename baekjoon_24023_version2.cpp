#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n, k;
    cin >> n >> k;

    int cal = 0;
    int s = 1;

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if ((t | k) != k)
        {
            cal = 0;
            s = i + 1;
        }
        else
        {
            cal |= t;
            if (cal == k)
            {
                cout << s << " " << i << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}