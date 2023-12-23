#include <bits/stdc++.h>

using namespace std;

int const MOD = 998244353;

#define file "sumpath"

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	int n, m; cin >> n >> m;
	int arr[2208][2208];
	int f[2209][2208] = {};
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){	
			char x; cin >> x;
			arr[i][j] = x - '0';
			f[i][j] = ((f[i - 1][j] + f[i][j - 1]) % MOD + f[i - 1][j - 1]) % MOD;
			arr[i][j] = ((arr[i - 1][j] + arr[i][j - 1]) % MOD + (arr[i - 1][j - 1] + 1LL * f[i][j] * arr[i][j] % MOD) % MOD) % MOD;
		}
		
	cout << arr[n][m];	
	return 0;
}