#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1002;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, m; cin >> n >> m;	
	int arr[N][N];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];

	ll b1[N][N] = {}, b2[N][N] = {}, g1[N][N] = {}, g2[N][N] = {};

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			b1[i][j] = max(b1[i - 1][j], b1[i][j - 1]) + arr[i][j];
	
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			b2[i][j] = max(b2[i + 1][j], b2[i][j + 1]) + arr[i][j];

	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			g1[i][j] = max(g1[i][j - 1], g1[i + 1][j]) + arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			g2[i][j] = max(g2[i][j + 1], g2[i - 1][j]) + arr[i][j];

	ll ans = 0;
	for (int i = 2; i <= n - 1; i++)
		for (int j = 2; j <= m - 1; j++){
			ll a = g1[i + 1][j] + b1[i][j - 1] + g2[i - 1][j] + b2[i][j + 1];
			ll b = g1[i][j - 1] + b1[i - 1][j] + g2[i][j + 1] + b2[i + 1][j];
			ans = max({ans, a, b}); 
		}
	
	
	cout << ans;
	return 0;
}

//fun fact: https://codeforces.com/contest/429/problem/B