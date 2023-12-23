#include <bits/stdc++.h>

using namespace std;

string s;

int const MOD = 1e9 + 7;

int dp[10001][3][2];

int calc(int i, int rmd, int is){
	if (i == s.size()) return (rmd == 0 && !is);
	
	int &ans = dp[i][rmd][is];
	if (ans != -1) return ans;
	ans = 0;
	
	for (int d = 0; d <= (is? s[i] - '0': 9); d++)
		(ans += calc(i + 1, (rmd + d * d) % 3, is & (d == s[i] - '0'))) %= MOD;
		
	return ans;
}

int main(){
	cin >> s;
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(0, 0, 1);
	return 0;
}