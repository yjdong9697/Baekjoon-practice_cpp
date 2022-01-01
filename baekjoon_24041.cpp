#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<long long, long long> ii;

int main(void){
    fastio;
    int n, g, k;
    cin >> n >> g >> k;

    vector<ii> must;
    vector<ii> select;

    for(int i = 0; i < n; i++){
        ll s, l, o;
        cin >> s >> l >> o;
        if(o == 0LL){
            must.push_back(make_pair(s, l));
        }
        else{
            select.push_back(make_pair(s, l));
        }
    }

    ll start = 1LL;
    ll end = 2000000001LL;
    while(start < end){
        ll mid = (start + end) / 2LL;

        ll val = 0;

        for(int i = 0; i < must.size(); i++){
            val += max(1LL, mid - must[i].second) * must[i].first;
            if(val > g) break;
        }

        vector<ll> q;

        for(int i = 0; i < select.size(); i++){
            q.push_back(max(1LL, mid - select[i].second) * select[i].first);
        }

        sort(q.begin(), q.end());


        for(int i = 0; i < (static_cast<long long>(q.size()) - k); i++){
            val += q[i];
            if (val > g) break;
        }

        if(val <= g) start = mid + 1LL;
        else end = mid;
    }
    cout << start - 1 << "\n";
    return 0;
}