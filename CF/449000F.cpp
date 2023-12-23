#include <bits/stdc++.h>

using namespace std;

int const N = 4e5 + 1;
int const MOD = 998244353;

int p[N];

int main(){
	int s; cin >> s;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];	
	
	int f[N] = {0, 0, 1};
	for (int i = 3; i <= n; i++) 
		f[i] = 1LL * (i - 1) * (((p[i] == -1) * f[i - 2] + f[i - 1]) % MOD) % MOD;
		
	for (int i = 1; i <= n; i++) cerr << f[i] << " ";
		cout << f[n] << "\n";	
	return 0;
}