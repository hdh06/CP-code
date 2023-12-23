#include <bits/stdc++.h>

using namespace std;

int const MOD = 998244353;

int const N = 5e5 + 1;
int const K = 30;

int arr[K][N];
int maxx[K][N];

int main(){
	int n, k, m; cin >> n >> k >> m;
	
	for (int i = 1; i <= m; i++){
		int l, r, x; cin >> l >> r >> x;
		for (int j = 0; j < k; j++){
			if (!!(x & (1 << j))){
				for (int k = l; k <= r; k++) arr[j][k] = 1;	
			}else{
				maxx[j][l] = 1;
			}
		}
	}
	
	for (int j = 0; j < k; j++){
		for (int i = 1; i <= n; i++){
			if (maxx[j][i]) maxx[j][i] = i;
			else maxx[j][i] = maxx[j][i - 1];
		}
	}
	
	int dp[N] = {};
	dp[0] = 1;
	int sum[N] = {};
	sum[0] = 1;
	int ans = 1;
	for (int j = 0; j < k; j++){
		for (int i = 1; i <= n; i++){
			dp[i] = dp[i - 1];
			if (!arr[j][i] && i > 1)
				dp[i] += sum[i - 2] - (maxx[j][i] > 1? sum[maxx[j][i] - 2]: 0);
			
			sum[i] = sum[i - 1] + (arr[j][i]? 0: dp[i]);
		}
		ans = ans * dp[n];
		if (j == k - 1){
			for (int i = 1; i <= n; i++) cerr << dp[i] << " " << sum[i] << " " << maxx[j][i] << " " << arr[j][i] << "\n";
		}
		// cerr << dp[n] << "\n";
	} 
	cout << ans;
	// cerr << 3 ^ 0 << " " << 3 ^ 1 << " " << 3 ^ 2 << " " << 3 ^ 3 << "\n";
 	return 0;
}