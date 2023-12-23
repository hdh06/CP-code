#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const MAXV = N * 6;

typedef long double ldb;

int main(){
	int n, a, b; cin >> n >> a >> b;
	ldb dp[MAXV] = {1};
	for (int i = 1; i <= n; i++){
		for (int k = MAXV - 1; k >= 0; k--){
			ldb sum = 0;
			for (int j = 1; j <= min(6, k); j++)
				sum += dp[k - j];
			dp[k] = sum / 6.0;	
		}
	}
	
	ldb ans = 0;
	for (int k = a; k <= b; k++)
		ans += dp[k];
	
	cout << setprecision(6) << fixed << ans;
	return 0;
}