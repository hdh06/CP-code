#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

typedef long long ll;

int main(){
	int n; cin >> n;
	ll arr[N] = {};
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
		
	ll f[N] = {}, g[N] = {};
	f[n] = arr[n];
	for (int i = n - 1; i >= 1; i--)
		f[i] = max(f[i + 1], arr[i]),
		g[i] = 2LL * arr[i] + 3LL * f[i + 1];
	
	f[n - 1] = g[n - 1];
	for (int i = n - 2; i >= 1; i--)
		f[i] = max(f[i + 1], g[i]),
		g[i] = arr[i] + f[i + 1];
	
	cout << *max_element(g + 1, g + n - 2 + 1);
	return 0;
}