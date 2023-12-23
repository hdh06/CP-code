#include <bits/stdc++.h>

using namespace std;

int const N = 31;
int const M = 1001;

long long dp[M] = {};

int main(){	
	int t, w, n; 
	while(cin >> t >> w >> n){
		int d[N], v[N];
		for (int i = 1; i <= n; i++) cin >> d[i] >> v[i]; 

		for (int i = 1; i < M; i++) dp[i] = 0;

		long long ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = t; j >= 1; j--){
				int del = 3*d[i]*w;
				if (j - del >= 0) dp[j] = max(dp[j], dp[j - del] + v[i]);
				ans = max(ans, dp[j]);
			}
		}
		cout << ans << endl;
	}
		
	return 0;
}