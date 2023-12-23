//http://www.usaco.org/index.php?page=viewproblem2&cpid=495
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
#define file "marathon"

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

int n, q;
ii cp[N + 1];

struct node{
	ll minn, sum;
	node(){minn = LLONG_MAX;}
	node(ll minn, ll sum) :minn(minn), sum(sum) {}
}tree[N << 2];

int dis(ii a, ii b){
	return abs(a.st - b.st) + abs(a.nd - b.nd);
}

void upd(int pos, int x = 1, int l = 1, int r = n){
	if (pos < l || r < pos) return;
	if (l == r){
		tree[x].sum = dis(cp[pos - 1], cp[pos]);
		tree[x].minn = - dis(cp[pos - 1], cp[pos]) - dis(cp[pos], cp[pos + 1]) + dis(cp[pos - 1], cp[pos + 1]);  
		return;
	}
	int mid = (l + r) >> 1;
	upd(pos, 2 * x, l, mid);
	upd(pos, 2 * x + 1, mid + 1, r);
	tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
	tree[x].minn = min(tree[2 * x].minn, tree[2 * x + 1].minn);
}

node get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return node(LLONG_MAX, 0);
	if (L <= l && r <= R) return tree[x];
	int mid = (l + r) >> 1;
	node A = get(L, R, 2 * x, l, mid);
	node B = get(L, R, 2 * x + 1, mid + 1, r);
	return node(min(A.minn, B.minn), A.sum + B.sum);
}

void solve(){	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> cp[i].st >> cp[i].nd;
	// cp[0] = cp[1];
	// cp[n + 1] = cp[n];
		
	for (int i = 1; i <= n; i++)
		upd(i);
	
	while (q--){
		char c; cin >> c;
		if (c == 'Q'){
			int l, r; cin >> l >> r;
			int sum = get(l + 1, r).sum;
			int minn = get(l + 1, r - 1).minn;
			cout << sum + minn << "\n";
		}
		if (c == 'U'){
			int i, x, y; cin >> i >> x >> y;
			cp[i] = {x, y};
			upd(i);
			if (i < n) upd(i + 1);
			if (i > 1) upd(i - 1);
		}
		// debug(dis(cp[2], cp[4]), dis(cp[2], cp[3]), dis(cp[3], cp[4]));
	}
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