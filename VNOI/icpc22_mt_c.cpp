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

int const N = 1e5 + 1;
int const K = 11;

int n, k;
int arr[N];

ll tree[K][N];
void upd(int z, int pos, ll k){
	for (int i = pos; i < N; i += i & -i) tree[z][i] += k;
}
ll get(int z, int pos){
	ll ans = 0;
	for (int i = pos; i > 0; i -= i & -i)
		ans += tree[z][i];
	return ans;
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int a, b; cin >> a >> b;
		arr[a] = b;
	}
	
	ll dp[N][K] = {};
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			if (j == 1) dp[i][j] = 1;
			else dp[i][j] = get(j - 1, arr[i]);	
		}
		for (int j = 1; j <= k; j++)
			upd(j, arr[i], dp[i][j]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans += dp[i][k];
	
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