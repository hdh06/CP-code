#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int main(){
	int n; cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++) ans *= 2, ans %= MOD;
	cout << ans;	
	return 0;
}