#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int pi[1000001];
vector<int> r;

void get_pi(string v){
	int m = v.size(), j = 0;
	for(int i = 1; i < m; i++){
		while(j > 0 && v[i] != v[j]){
			j = pi[j - 1];
		}
		if(v[i] == v[j]){
			pi[i] = ++j;
		}
	}
}

int kmp(string v1, string v2){
	get_pi(v2);
	int n = v1.size(), m = v2.size(), j = 0;
	int result = 0;
	for(int i = 0; i < n; i++){
		while(j > 0 && v1[i] != v2[j]){
			j = pi[j - 1];
		}
		if(v1[i] == v2[j]){
			if(j == m - 1){
				result++;
				r.push_back(i - m + 2);
				j = pi[j];
			}
			else j++;
		}
	}
	return result;
}

int main() {
	fastio;
	string s, p;
	getline(cin, s);
	getline(cin, p);
	cout << kmp(s, p) << "\n";
	for(int i = 0; i < r.size(); i++){
		cout << r[i] << " ";
	}
	cout << "\n";
	return 0;
}