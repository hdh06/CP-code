#include <bits/stdc++.h>

using namespace std;

int const N = 2002;
int const M = 2002;
int const MOD = 1e9 + 7;

typedef long long ll;

ll dp[N][M][2] = {};

int m, d_magic;
string a, b;
int p = 1;

int next_state_rmd(int d, int k, int rmd){
	int tich = d%m;
	tich *= p;
	return (tich%m + rmd)%m;
}

int num(char c){return c - '0';}

ll f(string s){
	p = 1;
	reverse(s.begin(), s.end());
	s = ' ' + s;
	int n = s.size();

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int tight = 0; tight <= 1; tight++) dp[i][j][tight] = 0;
		}
	}

	dp[0][0][0] = dp[0][0][1] = 1;

	for (int i = 0; i < n - 1; i++){
		if (i >= 1) p = (p*(10%m))%m;
		for (int tight = 0; tight <= 1; tight++){
			for (int rmd = 0; rmd <= m - 1; rmd++){
				if (tight){
					if ((n - i - 1) % 2 == 0){
						if (d_magic > num(s[i + 1])) continue;
						int next_rmd = next_state_rmd(d_magic, i, rmd);
						dp[i + 1][next_rmd][1] += (d_magic < num(s[i + 1])?dp[i][rmd][0]:dp[i][rmd][1]);
						dp[i + 1][next_rmd][1] %= MOD;
					}else{
						for (int d = 0; d <= num(s[i + 1]); d++){
							if (d == d_magic) continue;
							int next_rmd = next_state_rmd(d, i, rmd);
							dp[i + 1][next_rmd][1] += (d < num(s[i + 1]))?dp[i][rmd][0]:dp[i][rmd][1];
							dp[i + 1][next_rmd][1] %= MOD;
						}
					}
					
				}
				else{
					if ((n - i - 1) % 2 == 0){
						int next_rmd = next_state_rmd(d_magic, i, rmd);
						dp[i + 1][next_rmd][0] += dp[i][rmd][0];
						dp[i + 1][next_rmd][0] %= MOD;
					}else{
						for (int d = 0; d <= 9; d++){
							if (d == d_magic) continue;
							int next_rmd = next_state_rmd(d, i, rmd);
							dp[i + 1][next_rmd][0] += dp[i][rmd][0];
							dp[i + 1][next_rmd][0] %= MOD;
						}
					}
					
				}
			}	
		}
		
	}
	return dp[n - 1][0][1];
}

bool g(string s){
	s = ' ' + s;
	ll rmd = 0;
	for (int i = 1; i < s.size(); i ++){
		if ((i & 1) == 0 && num(s[i]) != d_magic) return false;
		if ((i & 1) == 1 && num(s[i]) == d_magic) return false;
		rmd = (rmd*(10%m) + num(s[i])%m)%m;
	}
	if (rmd == 0) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("inp.inp", "r", stdin); 
	// freopen("out.out", "w", stdout);
	cin >> m >> d_magic;
	cin >> a >> b;

	cout << ((f(b) - f(a) + MOD) %MOD + g(a))%MOD;
	return 0;
}