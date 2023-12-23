#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "flie"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

int const N = 1e3 + 1, M = 21;

int n, m;
pair<vi, int> arr[N];

vi g[N];

int c[N]; 

int vis[N];

void clr(int v){
	if (vis[v]) return;
	vis[v] = 1;
	int mex = 0;
	vi z;
	for (auto u: g[v]) if (vis[u])
		z.pb(c[u]);
	
	sort(all(z));
	for (auto x: z) if (mex == x) mex++;
	c[v] = mex;
	
	for (auto u: g[v]) clr(u);
}

bool cmp(vi a, vi b){
	for (int i = 0; i < m; i++)
		if (a[i] > b[i]) 
			return false;
	return true;
}

int dp[N];

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		arr[i].st.resize(m);
		arr[i].nd = i;
		for (int j = 0; j < m; j++)
			cin >> arr[i].st[j];
		sort(all(arr[i].st));
		
	}
	
	sort(arr + 1, arr + n + 1);
	// for (int i = 1; i <= n; i++)
		// debug(arr[i]);
	
	
	for (int i = 1; i <= n; i++){
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++) if (cmp(arr[j].st, arr[i].st)){
			// debug(i, j, cmp(arr[j], arr[i]));
			dp[i] = max(dp[i], dp[j] + 1);
		}
		g[dp[i]].pb(arr[i].nd);
	}
	
	// debug(vi(dp + 1, dp + n + 1));
	
	int k = *max_element(dp + 1, dp + n + 1);
	cout << k << "\n";
	for (int i = 1; i <= k; i++){
		cout << g[i].size() << " ";
		for (auto x: g[i]) cout << x << " ";
		cout << "\n";
	}
	
	
	// iota(Link + 1, Link + n + 1, 1);
	
	// for (int i = 1; i <= n; i++)
		// for (int j = i + 1; j <= n; j++){
			// int k = 1;
			// while (k < m && arr[i][k] == arr[j][k]) k++;
			// if (arr[i][k] == arr[j][k]) continue;
			// bool y = 1;
			// for (int z = k;z <= m; z++) if ((arr[i][k] <= arr[j][k] && arr[i][z] > arr[j][z]) || (arr[i][k] >= arr[j][k] && arr[i][z] < arr[j][z])){
				// // debug(i, j);
				// y = 0;
				// break;
			// }
			// if (y)
				// g[i].pb(j), g[j].pb(i);
		// }
// 		
	// for (int i = 1; i <= n; i++) clr(i);
// 	
	// vi ans[N] = {};
	// int maxx = 0;
	// for (int i = 1; i <= n; i++){	
		// maxx = max(maxx, c[i]);
		// ans[c[i]].pb(i);
	// }
// 	
	// cout << maxx + 1 << "\n";
	// for (int i = 0; i < n; i++) if (ans[i].size()){
		// cout << ans[i].size() << " ";
		// for (auto x: ans[i]) cout << x << " ";
		// cout << "\n";
	// }
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!