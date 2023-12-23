#include <bits/stdc++.h>

using namespace std;

int const N = 501;

typedef long long ll;

int main(){
	freopen("inp.inp", "r", stdin); 
	freopen("out.out", "w", stdout);	
	ll m; int n;
	cin >> m >> n;

	ll dp[N*N] = {};
	int c[N]; ll tong = 0;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		tong += c[i];
	}
	
	for (int i = 1; i <= n; i++){
		ll r = (m - tong)/c[i] + 1;
		dp[r*c[i] - (m - tong)] = r;
	}

	int back[N*N] = {};
	dp[0] = LLONG_MAX;
	for (int i = 0; i <= tong; i++){
		dp[i] = LLONG_MAX;
		for (int j = 1; j <= n; j++) if (i - c[i] >= 0 && dp[i - c[j]] != LLONG_MAX){
			if (dp[i] > dp[i - c[j]] + 1){
				dp[i] = dp[i - c[j]] + 1;
				back[i] = j;
			}
		}
		cout << (dp[i] == LLONG_MAX?-1:dp[i]) << " \n"[i == tong];
	}

	if (dp[tong] == LLONG_MAX){
		cout << -1;
		return 0;
	}

	if (tong > m) tong = m;

	cout << dp[tong] << endl;

	int cnt[N] = {};
	int p = tong;
	while (p > 0){
		cnt[back[p]] ++;
		p = p - c[back[p]];
	}

	for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
	return 0;
}