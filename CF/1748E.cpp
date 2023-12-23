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

bool const SINGLE_TEST = 0;

int const N = 1e6 + 1;
int const L = 25;
int const MOD = 1e9 + 7;

int n, m;
int arr[N];
int rmq[N][L];

int rmax(int a, int b){
	if (arr[a] == arr[b]) return min(a, b);
	return arr[a] > arr[b]? a: b;
}
int rget(int l, int r){
	if (r < l) return -1;
	int k = log2(r - l + 1);
	return rmax(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

map<ii, int> dp;
map<int, vi> sum;

int calc(int l, int r, int x){
	if (r < l) return 0;
	if (l == r) return 1;
	
	int m = rget(l, r);
	
	if (dp.find({m, x}) != dp.end()) return dp[{m, x}];
	
	int a = rget(l, m - 1), b = rget(m + 1, r);	
	
	if (sum.find(a) == sum.end()){
		sum[a].assign(x, 0);
		for (int i = x - 1; i >= 1; i--)	
			sum[a][i] = calc(l, m - 1, i);
		for (int i = 1; i < x; i++)
			(sum[a][i] += sum[a][i - 1]) %= MOD;
	}
	if (sum.find(b) == sum.end()){
		sum[b].assign(x + 1, 0);
		for (int i = x; i >= 1; i--)
			sum[b][i] = calc(m + 1, r, i);
		for (int i = 1; i <= x; i++)
			(sum[b][i] += sum[b][i - 1]) %= MOD;
	}
		
	if (m == l) return dp[{m, x}] = sum[b][x];
	if (m == r) return dp[{m, x}] = sum[a][x - 1];
	return dp[{m, x}] = 1LL * sum[a][x - 1] * sum[b][x] % MOD;
}

void solve(){
	dp.clear(), sum.clear();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	for (int i = 1; i <= n; i++)
		rmq[i][0] = i;
	
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= n; i++)
			rmq[i][j] = rmax(rmq[i][j - 1], rmq[min(n, i + (1 << (j - 1)))][j - 1]);
	
	int ans = 0;
	for (int i = m; i >= 1; i--)
		(ans += calc(1, n, i)) %= MOD;
	cout << ans << "\n";
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