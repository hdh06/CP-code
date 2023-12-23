#include <bits/stdc++.h>

using namespace std;


int const MOD = 25071987;

int const N = 5002;

int dp[N][N] = {};

int main(){
	string a, b;	
	cin >> a >> b;

	a = ' ' + a;
	b = ' ' + b;

	for (int i = 1; i < a.size(); i++){
		for (int j = 1; j < b.size(); j++){
			if (a[i] == b[j]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1)%MOD;
			else dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j])%MOD - dp[i - 1][j - 1] + MOD)%MOD;
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}

	cout << dp[a.size() - 1][b.size() - 1];
	
	return 0;
}
