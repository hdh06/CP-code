#include <bits/stdc++.h>

using namespace std;

int const N = 20;
int const MOD = 1e9 + 7;

int n, m;
vector<int> g[N];

int dp[N][1 << N];

int pre[N + 1];
void init(){
	for (int i = 0; i < N + 1; i++)
		pre[i] = 1 << i;
}

int emrua(int v, int mask){
	mask |= pre[v];

	if (v == n - 1) return (mask == pre[n] - 1);
	if (mask == pre[n] - 1) return 0;

	if (dp[v][mask] != -1) return dp[v][mask];

	int ans = 0;
	for (auto u: g[v]) if ( (mask & pre[u]) == 0)
		(ans += emrua(u, mask)) %= MOD;
	
	return dp[v][mask] = ans;
}

int main(){
	init();
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
	}

	memset(dp, -1, sizeof dp);

	cout << emrua(0, 1);
	return 0;
}