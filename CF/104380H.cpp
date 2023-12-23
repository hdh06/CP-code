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

int const N = 2e5 + 1;

string s;
int n;
int q;

struct node{
	int ans, cnt0, cnt1;
	node(){}
	node(int ans, int cnt0, int cnt1) :ans(ans), cnt0(cnt0), cnt1(cnt1) {}
}tree[N << 2];

void merge(node &x, node a, node b){
	x.cnt0 = a.cnt0 + b.cnt0;
	x.cnt1 = a.cnt1 + b.cnt1;
	x.ans = a.ans + b.ans + min(a.cnt0 - a.ans, b.cnt1 - b.ans);
}

void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		tree[x] = node(0, 1, 0);
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	merge(tree[x], tree[2 * x], tree[2 * x + 1]);
}

void upd(int pos, int x = 1, int l = 1, int r = n){
	if (pos < l || r < pos) return;
	if (l == r){
		tree[x].cnt0 ^= 1;
		tree[x].cnt1 ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	upd(pos, 2 * x, l, mid);
	upd(pos, 2 * x + 1, mid + 1, r);
	merge(tree[x], tree[2 * x], tree[2 * x + 1]);
}

node get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return node(0, 0, 0);
	if (L <= l && r <= R) return tree[x];
	int mid = (l + r) >> 1;
	node ans;
	merge(ans, get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
	return ans;
}

void solve(){	
	cin >> s;
	n = s.size();
	
	build();
	
	for (int i = 0; i < n; i++) if (s[i] == '1') upd(i + 1);
	
	cin >> q;
	
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int pos; cin >> pos;
			upd(pos);
		}
		if (t == 2){
			int l, r; cin >> l >> r;
			cout << (r - l + 1) - get(l, r).ans * 2 << "\n";
		}
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