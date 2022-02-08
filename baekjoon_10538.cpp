#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const int MAX_SIZE = 2000;

int row_hash[MAX_SIZE][MAX_SIZE]; // 가로줄 해싱값
int hash_store[MAX_SIZE][MAX_SIZE]; // 최정 해싱값

// 가로 방향으로 해싱
void RowHashFind(string S, int m, int line) {
	int n = S.length();
	int power = 1, hash_value = 0;
	for (int i = 0; i <= n - m; i++) {
        if(i == 0){
            for(int j = 0; j < m; j++){
                hash_value = hash_value * 37 + S[i + j];
                if(j != m - 1) power = power * 37;
            }
        }
        else hash_value = 37 * (hash_value - S[i - 1] * power) + S[i + m - 1];
        row_hash[line][i] = hash_value;
	}
}

// 가로 방향으로 해싱한 것을 다시 세로 방향으로 해싱
void ColHashFind(int H, int W, int N, int M) {
	for (int i = 0; i <= M - W; i++) {
		int hash_value = 0, power = 1;
		for (int k = 0; k <= N - H; k++) {
			if (k == 0) {
				for (int t = 0; t < H; t++) {
					hash_value = hash_value + row_hash[H - t - 1][i] * power;
					if (t != H - 1) power = power * 5831;
				}
			}
			else hash_value = 5831 * (hash_value - row_hash[k - 1][i] * power) + row_hash[k+H - 1][i];
			hash_store[k][i] = hash_value;
		}
	}
}

int main() {
    fastio;
	int H, W, N, M;
	cin >> H >> W >> N >> M;
	string temp;
	for (int i = 0; i < H; i++) {
		cin >> temp;
		RowHashFind(temp, W, i);
	}
    ColHashFind(H, W, H, W);
    int cmp = hash_store[0][0];

	for (int i = 0; i < N; i++) {
		cin >> temp;
		RowHashFind(temp, W, i);
	}
	ColHashFind(H,W,N,M);
		
    int ret = 0;
	for (int i = 0; i <= N - H; i++)
		for (int j = 0; j <= M - W; j++)
			if (hash_store[i][j] == cmp) ret++;
			
	cout << ret << "\n";
	return 0;
}