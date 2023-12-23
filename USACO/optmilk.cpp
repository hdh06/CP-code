//http://www.usaco.org/index.php?page=viewproblem2&cpid=365
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
#define file "fiel"

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

bool const SINGLE_TEST = 1;
int const N = 1e5 + 1;

int n;
ll arr[N];

struct node{
	ll sum = 0;
	int l, r;
	node(){}
	node(ll sum, int l, int r) :sum(sum), l(l), r(r) {}
};

node tree[N << 2];

node merge(node a, node b){
	if (a.r < b.l - 1) return node(a.sum + b.sum, a.l, b.r);
	return node(a.sum + b.sum - min(arr[a.r], arr[b.l]), a.l, b.r);
}

void upd(int pos, int v, int x = 1, int l = 1, int r = n){
	if (pos < l || r < pos) return;
	if (l == r){
		arr[l] = v;
		tree[x] = node(v, pos, pos);
		return;
	}
	int mid = (l + r) >> 1;
	upd(pos, v, 2 * x, l, mid);
	upd(pos, v, 2 * x + 1, mid + 1, r);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

void solve(){	
	cin >> n; int d; cin >> d;
	for (int i = 1; i <= n; i++){
		ll x; cin >> x;
		upd(i, x);
	}
	
	ll ans = 0;
	while (d--){
		ll pos, v; cin >> pos >> v;
		upd(pos, v);
		ans += tree[1].sum;
		debug(tree[4].sum);
	}
	cout << ans;
}	

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef LOCAL
		cerr << "USACO is fun haha\n";
	#else
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!