#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const W = 10001;

int p2(int a){
	return a * a;
}

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (auto &x: a) cin >> x;
	for (auto &x: b) cin >> x;	

	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) s1 += a[i] + b[i], s2 += p2(a[i]) + p2(b[i]);

	bool dp[N][W] = {};
	dp[0][a[0]] = dp[0][b[0]] = 1;
	for (int i = 1; i < n; i++){
		for (int j = a[i]; j < W; j++) dp[i][j] |= dp[i - 1][j - a[i]];
		for (int j = b[i]; j < W; j++) dp[i][j] |= dp[i - 1][j - b[i]];
	}	

	int ans = INT_MAX;

	for (int i = 0; i <= s1; i++) if (dp[n - 1][i])
		ans = min(ans, p2(i) + p2(s1 - i));
	
	cout << (n - 2)*s2 + ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}