#include <bits/stdc++.h>

using namespace std;

string s;

int const MOD = 1e9 + 7;

int c(int i, int n){return n - i - 1;}
int num(char x){return x - '0';}
//    1 0    1   0
// 1: =/< 2: >/ <=
int const N = 1e5 + 1;

int dp[N][11][2][2];

int emrua(int n, int last, bool t1, bool t2){
	if (n == (s.size() + 1) / 2)
		return !t1 || !t2;

	if (dp[n][last + 1][t1][t2] != -1) return dp[n][last + 1][t1][t2];

	int ans = 0;
	for (int i = (last == -1? -1: 0); i <= (t1? num(s[n]): 9); i++) if ((last == -1) || abs(last - i) >= 5){
		if (last == -1 && i == 0) continue;
		bool next_t2; int o = num(s[c(n, s.size())]);
		if (t2){
			if (i >= o) next_t2 = 1;
			else next_t2 = 0;
		}else{
			if (i > o) next_t2 = 1;
			else next_t2 = 0;
		}
		(ans += emrua(n + 1, i, (t1 & (i == num(s[n]))), next_t2)) %= MOD;
	}	
	return dp[n][last + 1][t1][t2] = ans;
	return ans;
}

int main(){
	cin >> s;	
	
	if (s.size() % 2 == 0) s = string(s.size() - 1, '9');

	memset(dp, -1, sizeof dp);
	cout << (emrua(0, -1, 1, 0) - 1 + MOD) % MOD;
	return 0;
}