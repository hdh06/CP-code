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

int const N = 5e4 + 1;

int n, q;
int arr[N];

ii opt(ii a, ii b){return mp(max(a.st, a.nd), min(b.st, b.nd));}

ii tree[N << 2];
void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		tree[x] = mp(arr[l], arr[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	tree[x] = opt(tree[2 * x], tree[2 * x + 1]);
}

ii get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return mp(0, INT_MAX);
	if (L <= l && r <= R) return tree[x];
	int mid = (l + r) >> 1;
	return opt(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
}

void solve(){	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build();
	while (q--){
		int a, b; cin >> a >> b;
		ii p = get(a, b);
		debug(p);
		cout << p.nd - p.st << "\n";
	}
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