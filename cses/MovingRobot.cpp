#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 202
#endif

using namespace std;

typedef long double ldb;

int const K = 105;

ldb dp[K][9][9], ans[9][9];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isInbound(int x, int y){
	return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

int main(){
	int k; cin >> k;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			ans[i][j] = 1;
			
	for (int x = 1; x <= 8; x++)
		for (int y = 1; y <= 8; y++){		
			
			for (int k = 0; k < K; k++)
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)	
						dp[k][i][j] = 0;
			dp[0][x][y] = 1; 
		
			for (int k = 0; k < K - 1; k++){
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++){
						
						ldb tdir = 0;
						for (int d = 0; d < 4; d++)
							if (isInbound(i + dx[d], j + dy[d]))
								tdir ++;
								
						for (int d = 0; d < 4; d++) if (isInbound(i + dx[d], j + dy[d]))	
							dp[k + 1][i + dx[d]][j + dy[d]] += dp[k][i][j] / tdir;
					}
			}
			
			
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
					ans[i][j] *= (1 - dp[k][i][j]);
			
		}
	
	ldb sum = 0;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			sum += ans[i][j];
				
	cout << setprecision(6) << fixed << sum;
	return 0;
}