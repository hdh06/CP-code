#include <bits/stdc++.h>

using namespace std;

int const MOD = 25071987;
int const N = 1e5 + 5;

long long dp[N]; bool ishong[N];

int main(){
	int n, k;
	cin >> n >> k;
	while(k--){
		int temp;
		cin >> temp;
		ishong[temp] = true;
	}

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) if(!ishong[i]){
		dp[i] = (dp[i - 1] + dp[i - 2])%MOD;
	}	

	cout << dp[n];
	return 0;
}