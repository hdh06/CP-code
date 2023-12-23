#include <bits/stdc++.h>

using namespace std;

int const N = 52;

int L, n;
int arr[N];

int dp[N][N];

int calc(int l, int r){
	if (l > r) return 0; 
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r)
		return dp[l][r] = arr[r + 1] - arr[l - 1];
	int ans = INT_MAX;
	for (int i = l; i <= r; i++)
		ans = min(ans, calc(l, i - 1) + calc(i + 1, r) + arr[r + 1] - arr[l - 1]);
	return dp[l][r] = ans;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	arr[n + 1] = L;
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(1, n) << "\n";
	cin >> L;
}

int main(){
	cin >> L;
	while (L) solve();
	return 0;
}