#include <bits/stdc++.h>

using namespace std;

string s;

int num(char x) {return x - '0';}

int const N = 10001;
int const MOD = 1e9 + 7;

int dp[N][17][11][2][2];

string f;

int emrua(int n, int rmd, int last, bool tight, bool is){
	if (n == s.size()){
		if (rmd == 0) return 1;
		return 0;
	}
	if (dp[n][rmd][last][tight][is] != -1) return dp[n][rmd][last][tight][is];
	int ans = 0;
	for (int i = 0; i <= (tight? num(s[n]): 9); i++) if ((is & (i == 0)) | (i != last)){
		(ans += emrua(n + 1, (rmd * 10 % 17 + i) % 17, i, tight & (i == num(s[n])), (i == 0) & is)) %= MOD;
	}
	return dp[n][rmd][last][tight][is] = ans;
}
 
bool g(string x){
	int rmd = 0;
	char last = '~';
	for (auto d: x){
		rmd = (rmd * 10 % 17 + num(d)) % 17;
		if (d == last) return false;
		last = d;
	}
	return (rmd == 0);
	
}

int solve(string x){
	s = x;
	memset(dp, -1, sizeof dp);
	return emrua(0, 0, 10, 1, 1);
}

int main(){
	string L; cin >> L;
	string R; cin >> R;
	cout << ((solve(R) - solve(L) + MOD) % MOD + g(L)) % MOD << "\n";
	return 0;
}