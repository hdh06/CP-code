#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

int num(char c){return c - '0';}

int main(){
	int n, k; cin >> n >> k;
	string s; cin >> s;

	s = ' ' + s;
	int snum[N] = {}, ssum[N] = {};
	int p10[N]; p10[n + 1] = 1; 
	for (int i = n; i >= 1; i--){
		p10[i] = p10[i + 1] * 10;
		snum[i] = snum[i + 1] + num(s[i]) * p10[i + 1];
		ssum[i] = ssum[i + 1] + snum[i]; 
	}	

	for (int i = 1; i <= n; i++) cout << snum[i] << " \n"[i == n];
	for (int i = 1; i <= n; i++) cout << ssum[i] << " \n"[i == n];

	int dp[N] = {}, psum[N] = {};
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			dp[i] = dp[i] + ssum[1] - (i - 1) * snum[i + 1];
			psum[i] = psum[i - 1] + dp[i];
		}
	}	

	cout << dp[n];
	return 0;
}