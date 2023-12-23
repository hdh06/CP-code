#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

int dp[N][13];

int emrua(int n, int rmd, int st){
	if (n == 0){
		if (rmd == 0) return 1;
		return 0;
	}

	if (dp[n][rmd] != -1) return dp[n][rmd];

	int ans = 0;
	for (int i = st; i <= 9; i++) if (i != 1 && i != 3)
		(ans += emrua(n - 1, (rmd * 10 % 13 + i) % 13, 0)) %= MOD;
	return dp[n][rmd] = ans;
}

int main(){
	int n; cin >> n;

	memset(dp, -1, sizeof dp);

	cout << emrua(n, 0, 1);
	return 0;
}