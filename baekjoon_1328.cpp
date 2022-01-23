#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int dp[101][101][101];
int n, l, r;
const int MOD = 1000000007;

ll memoi(int n, int l, int r){
	if(n < 0 || l < 0 || r < 0) return 0; // OB
	int& ret = dp[n][l][r];
	if(ret != -1) return ret;
	return ret = (memoi(n - 1, l - 1, r) + memoi(n - 1, l, r - 1) + memoi(n - 1, l, r) * (n - 2)) % MOD;
}

int main() {
	fastio;
	memset(dp, -1, sizeof(dp));
	cin >> n >> l >> r;
	dp[1][1][1] = 1; // Base case
	cout << memoi(n, l, r) << "\n";
	return 0;
}