#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 3e5 + 1;
int const M = 41;

int n, m;
int c[N], w[M];

int dp[1 << 22];
ll g[M];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		c[i] -= 1;
	}
	for (int i = 1; i < n; i++){
		g[c[i]] |= 1LL << c[i + 1];
		g[c[i + 1]] |= 1LL << c[i];
	}

	for (int i = 0; i < m; i++)
		cin >> w[i];

	int A = (m + 1) / 2, B = m - A;
	
	fill(dp, dp + (1 << 22), INT_MAX);

	for (int mask = 0; mask < (1 << A); mask++){
		if (c[1] < A && !(mask & (1 << c[1]))) continue;
		if (c[n] < A && !(mask & (1 << c[n]))) continue;
		int cost = 0;
		for (int i = 0; i < A; i++)	if ((1 << i) & mask)
				cost += w[i];
				
		bool flag = 1;
		for (int i = 0; i < A; i++)
			for (int j = 0; j < A; j++) if (g[i] & (1LL << j))
				if (!(mask & (1 << i)) && !(mask & (1 << j)))
					flag = 0;
			
		if (!flag) continue;
		int con = 0;
		for (int i = 0; i < A; i++) if (!(mask & (1 << i)))
			for (int j = A; j < B + A; j++) if (g[i] & (1LL << j))
				con |= 1 << (j - A);
			
		
		dp[con] = min(dp[con], cost);
		// debug(mask, con, dp[con]);
	}
	
	int ans = INT_MAX;
	for (int mask = 0; mask < (1 << B); mask++){
		for (int i = 0; i < B; i++) if (!(mask & (1 << i)))
			dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask]);
			
		if (c[1] >= A && !(mask & (1 << (c[1] - A)))) continue;
		if (c[n] >= A && !(mask & (1 << (c[n] - A)))) continue;
		
		int cost = 0;
		for (int i = A; i < B + A; i++) if (mask & (1 << (i - A)))
			cost += w[i];
		
		bool flag = 1;
		for (int i = A; i < B + A; i++)
			for (int j = A; j < B + A; j++) if (g[i] & (1LL << j))
				if (!(mask & (1 << (i - A))) && !(mask & (1 << (j - A))))
					flag = 0;
		
		if (!flag) continue;
		if (dp[mask] != INT_MAX) dp[mask] += cost;
		// debug(mask, dp[mask]);
		ans = min(ans, dp[mask]);
	}
	
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!