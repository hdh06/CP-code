#include <bits/stdc++.h>

using namespace std;

int const N = 17;
int const V = 1e5 + 1;

int conv(string s){
	int ans = 0;
	for (auto x: s)
		ans = (x - '0') + ans * 2;
	return ans;
}

int cnt[V] = {};

int dp[V][N][N];

int emrua(int mask, int n, int k){
	if (n == -1)
		return (k == 0) * cnt[mask];

	if (k < 0) return 0;

	if (dp[mask][n][k] != -1) return dp[mask][n][k];
	
	int ans = 0;
	for (int i = 0; i <= 1; i++){
		int that = !!(mask & (1 << n));
		if (that != i)
			ans += emrua(mask ^ (1 << n), n - 1, k - 1);
		else ans += emrua(mask, n - 1, k);
	}

	return dp[mask][n][k] = ans;
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n, m, k; cin >> n >> m >> k;
	while (n--){
		string x; cin >> x;
		cnt[conv(x)]++;
	}

	memset(dp, -1, sizeof dp);

	int ans = 0;

	for (int i = 0; i < V; i++) if (cnt[i] > 0){
		ans += cnt[i] * emrua(i, m - 1, k);
		// cerr << i << ": " << bitset<4>(i) << " -> " << cnt[i] << " " << emrua(i, m - 1, k) << "\n";
	}
	cout << ans / 2;
	return 0;
}