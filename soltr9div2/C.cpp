#include <bits/stdc++.h>

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
#define file "C"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 5e5 + 5;
ll const INF =  1LL * N * 1e9 + 1;

struct MFtree{
	int n;
	vl tree;
	MFtree(){}
	MFtree(ll _n, ll init_val = -INF){
		n = _n;
		tree.assign(n + 1, init_val);
	}
	
	void upd(int x, ll val){
		for (int i = x; i <= n; i += i & -i)
			tree[i] = max(tree[i], val);
	}
	
	ll get(int x){
		ll ans = -INF;
		for (int i = x; i > 0; i -= i & -i)
			ans = max(ans, tree[i]);
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	ll psum[N] = {};
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		psum[i] = psum[i - 1] + x;
	}
	
	vl b(psum, psum + n + 1);
	sort(all(b));	
	b.erase(unique(all(b)), b.end());
	for (int i = 0; i <= n; i++)
		psum[i] = lb(all(b), psum[i]) - b.begin() + 1;
	
	MFtree pos(n + 2), neg(n + 2);
	vl zro(n + 2, -INF);
	pos.upd(psum[0], 0 - 1 + 1);
	neg.upd(n + 1 - psum[0] + 1, 0 + 1 - 1);
	zro[psum[0]] = 0;
	
	ll dp[N] = {0};
	for (int i = 1; i <= n; i++){
		dp[i] = max({
					 pos.get(psum[i] - 1) + i, 
					 neg.get(n + 1 - psum[i] + 1 - 1) - i, 
					 zro[psum[i]]
					});
		pos.upd(psum[i], dp[i] - i); // dp[i] - (i + 1) + 1
		neg.upd(n + 1 - psum[i] + 1, dp[i] + i); // dp[i] + (i + 1) - 1
		zro[psum[i]] = max(zro[psum[i]], dp[i]);
	}
	
	cout << dp[n];
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen("gen.inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!