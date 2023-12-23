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

int const N = 6e5 + 1;

int n, e;
ii arr[N];

// int dp[N];

int z;
int tree[2][N << 2];
void upd(int tree[], int pos, int val, int x = 1, int l = 0, int r = z - 1){
	// if (x == 1) debug(pos, val);
	if (r < pos || pos < l) return;
	if (l == r){
		tree[x] = val;
		return;
	}
	int mid = (l + r) >> 1;
	upd(tree, pos, val, 2 * x, l, mid);
	upd(tree, pos, val, 2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}
int get(int tree[], int L, int R, int x = 1, int l = 0, int r = z - 1){
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return tree[x];
	int mid = (l + r) >> 1;
	return max(get(tree, L, R, 2 * x, l, mid), get(tree, L, R, 2 * x + 1, mid + 1, r));
}
vi b;
int key(int v){
	return lb(all(b), v) - b.begin();
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> n >> e;
	for (int i = 1; i <= n; i++) cin >> arr[i].st >> arr[i].nd;
	
	for (int i = 1; i <= n; i++) b.pb(arr[i].nd), b.pb(max(0, arr[i].nd - e)), b.pb(max(0, arr[i].nd - 2 * e));
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	z = b.size();
	
	// debug(b);
	
	sort(arr + 1, arr + n + 1);
	
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int x = key(arr[i].nd), y = key(max(0, arr[i].nd - e)), z = key(max(0, arr[i].nd - 2 * e));
		int a = get(tree[1], y, x) + 1;
		int b = max(get(tree[0], y, x) + 1, get(tree[1], z, x) + 2);
		upd(tree[1], x, a);
		upd(tree[0], x, b);
		// debug(i, a, b, z, y, x);
		ans = max(ans, max(a, b));
	}
	cout << ans << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!