#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const N = 5001;

int dp[N];

int n, k;
string s;

int main(){
	cin >> n >> k >> s;
	
	s = ' ' + s;
	
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++){
		int a = 0, b = 0;
		for (int j = i; j >= 1; j--){
			if (s[j] == '1') a++; else b++;
			if (abs(a - b) <= k)
				(dp[i] += dp[j - 1]) %= MOD;
		}
	}
	
	cout << dp[n];
	return 0;
}