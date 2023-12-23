#include <bits/stdc++.h>

using namespace std;

int const N = 3031;

int main(){
	string a, b; 
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	int dp[N][N] = {};
	for (int i = 1; i < N; i++) dp[i][0] = i;
	for (int i = 1; i < N; i++) dp[0][i] = i;

	for (int i = 1; i < a.size(); i++){
		for (int j = 1; j < b.size(); j++){
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
			if (a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
		}
	}	
	// for (int i = 0; i < a.size(); i++){
	// 	for (int j = 0; j < b.size(); j++) cout << dp[i][j] << " \n"[j == b.size() - 1];
	// }

	cout << dp[a.size() - 1][b.size() - 1];
	return 0;
}