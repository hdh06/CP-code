#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

int main(){
	string a, b; cin >> a >> b;
	a = " " + a;
	b = " " + b;

	int dp[N][N] = {};

	for (int i = 1; i < a.size(); i++) dp[i][0] = i;
	for (int j = 1; j < b.size(); j++) dp[0][j] = j;

	for (int i = 1; i < a.size(); i++){
		for (int j = 1; j < b.size(); j++){
			dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1,
						dp[i - 1][j - 1] + (a[i] != b[j])});
		}
	}	

	// for (int i = 0; i < a.size(); i++)
	// 	for (int j = 0; j < b.size(); j++)
	// 		cout << dp[i][j] << " \n"[j == b.size() - 1];	
	
	cout << dp[a.size() - 1][b.size() - 1];
	return 0;
}