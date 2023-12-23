#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m; ll W;

int const N = 1e2 + 1;

vector<pair<int, int> > g[N];
#define st first
#define nd second

ll dp[N][10000];

ll calc(int v, ll k){
	if (k == 0) return 0;
	if (dp[v][k] != -1) return dp[v][k];
	ll ans = LLONG_MAX;
	for (auto u: g[v])
		ans = min(ans, calc(u.st, k - 1) + u.nd);
	return dp[v][k] = ans;
}
ll minn(ll k){
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; i++) ans = min(ans, calc(i, k));
	return ans;
}

int main(){
	cin >> n >> m >> W;
	while (m--){
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
	}

	memset(dp, -1, sizeof dp);

	ll ans = 0;
	for (ll l = 0, r = W; l <= r;){
		ll mid = (l + r) >> 1;
		if (minn(mid) <= W){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}

	cout << ans;
	return 0;
}
