#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int const N = 1001, M = 101, MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int dp[N][M];
int p[N];

int emrua(int i, int k){
	if (k == s.size()) return mpow(26, n - i);
	if (i == n) return 0;
		
	if (dp[i][k] != -1) return dp[i][k];
	
	int ans = 0;
	for (int c = 'A'; c <= 'Z'; c++){
		int new_k = k;
		if (s[new_k] == c)
			new_k++;
		else{
			while (new_k && s[new_k] != c) new_k = p[new_k - 1];
			if (s[new_k] != c) new_k = 0;
			else new_k++;
		}
		(ans += emrua(i + 1, new_k)) %= MOD;
	}
	
	return dp[i][k] = ans;
}

int main(){
	cin >> n >> s;
	
	memset(dp, -1, sizeof dp);
	
	for (int j = 0, i = 1; i < s.size();)
		if (s[i] == s[j])
			p[i] = ++j, ++i;
		else{
			while (j && s[i] != s[j]) j = p[j - 1];
			if (s[i] != s[j])
				p[i] = 0, j = 0, i++;
		}
	
	cout << emrua(0, 0);
	return 0;
}