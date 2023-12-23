#include <bits/stdc++.h>

using namespace std;

int const K = 102;

typedef long double ldb;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int main(){
	int k; cin >> k;
	
	ldb dp[K][9][9] = {};
	
	for (int z = 1; z <= k; z++)
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++){
				ldb cnt = 0;
				for (int t = 0; t < 4; t++){
					int x = i + dx[t], y = j + dy[t];
					cnt += (1 <= x && x <= 8 && 1 <= y && y <= 8)
				}
				
				for (int t = 0; t < 4; t++)
					dp[z + 1][i + dx[t]][j + dy[t]] += dp[z][i][j] / cnt; 
			}
			
	int ans = 0; 
	cout << setprecision(6) << fixed << dp[n][]
	return 0;
}