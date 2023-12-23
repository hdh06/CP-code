#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1;
int const MOD = 1e9 + 7;

string s;

int dp[N][19][8];

int emrua(int n, int rmd, int mask){
	if (n == 0) return (rmd == 0);
	int &ans = dp[n][rmd][mask];
	if (ans != -1) return ans;
	ans = 0;
	for (int i = 0; i <= 9; i++){
		if (mask >> ((30 - i) % 3) & 1) continue;
		(ans += emrua(n - 1, (rmd * 10 % 19 + i) % 19, (mask == 0 && i == 0? 0: mask | 1 << (i % 3)))) %= MOD;
	}
	return ans;
}

int num(char c){return c - '0';}

int cnt(string s){
	int ans = 0;
	int mask = 0;
	int rmd = 0;
	for (int i = 0; i < s.size(); i++){
		for (int j = 0; j < num(s[i]); j++){
			if (mask >> ((30 - j) % 3) & 1) continue;
			(ans += emrua(s.size() - i - 1, (rmd * 10 % 19 + j) % 19, (mask == 0 && j == 0 ? 0 : mask | (1 << (j % 3))))) %= MOD; 
			// cout << s.size() - i - 1 << " " << (rmd * 10 % 19 + j) % 19 << " " << (mask == 0 && j == 0? 0 :mask | (1 << (j % 3))) << "\n";
			// cout << emrua(s.size() - i - 1, (rmd * 10 % 19 + j) % 19, (mask == 0 && j == 0? 0 :mask | (1 << (j % 3)))) << "\n";
		}
		if (mask >> ((30 - num(s[i])) % 3) & 1) break;
		mask |= 1 << (num(s[i]) % 3);
		rmd = (rmd * 10 % 19 + num(s[i])) % 19;
	}
	return ans;
}	

int main(){
	memset(dp, -1, sizeof dp);
	int t; cin >> t;
	while (t--){
		string L, R; cin >> L >> R;

		R = '0' + R;
		int x = R.size() - 1;
		while (R[x] == '9') x--;
		R[x]++;
		while (x < R.size()) R[++x] = '0';
		if (R[0] == '0') R.erase(0, 1);

		cout << (cnt(R) - cnt(L) + MOD) % MOD << "\n";
	}
	return 0;
}