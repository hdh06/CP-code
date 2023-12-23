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

int const N = 2e5 + 5;

struct line{
	int x, l, r, w;
	line(){}
	line(int x, int l, int r, int w): x(x), l(l), r(r), w(w) {};
};

int n;
vector<line> evn;

vi com;
int key(int val){
	return lb(all(com), val) - com.begin();
}

int tree[N << 2];
bool lz[N << 2];

//[i_____][i + 1____]

void down(int x, int l, int r){
	if (lz[x]){
		// debug("pk");
		int mid = (l + r) >> 1;
		tree[2 * x] = com[mid + 1] - com[l] - tree[2 * x];
		lz[2 * x] ^= 1;
		tree[2 * x + 1] = com[r + 1] - com[mid + 1] - tree[2 * x + 1];
		lz[2 * x + 1] ^= 1;
		lz[x] ^= 1;
	}
}

void upd(int L, int R, int x = 1, int l = 0, int r = com.size() - 1){
	// debug(L, R, x, l, r);
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		// debug(l, r, tree[x]);
		tree[x] = com[r + 1] - com[l] - tree[x];
		// debug(l, r, tree[x]);
		lz[x] ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	down(x, l, r);
	upd(L, R, 2 * x, l, mid);
	upd(L, R, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x] + tree[2 * x + 1];
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		evn.pb(line(a, b, d, 1));
		evn.pb(line(c, b, d, -1));
		com.pb(b);
		com.pb(d);
	}
	sort(all(com));
	com.erase(unique(all(com)), com.end());
	// com.pb(com.back() + 1);
	sort(all(evn), [](line a, line b){
		if (a.x != b.x) return a.x < b.x;
		return a.w < b.w;
	});
	
	// for (auto e: evn){
		// cerr << e.x << " " << e.l << " " << e.r << " " << e.w << "\n";
	// }
	
	// memset(tree, 0, sizeof tree);
	// debug(com);
	// upd(1, 2);
	// debug(tree[1]);
	
	int pre = 0;
	ll ans = 0;
	for (auto e: evn){
		if (e.x != pre)
			ans += 1LL * (e.x - pre) * tree[1];
		upd(key(e.l), key(e.r) - 1);
		pre = e.x;
	}
	// if (n == 3) cout << "9\n"; else
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
}//khong phai _HDH, _HDH ko xai template!!!