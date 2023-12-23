// http://www.usaco.org/index.php?page=viewproblem2&cpid=231

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
#define file "seating"

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

int const N = 5e5 + 1;

struct node{
	int Pre = 0, Suf = 0, Max = 0; // for finding in query 1
	int isAllOne = 0;
	int isInv = -1; // for lazy query 2
	
	node(){}
	node(int Pre, int Suf, int Max, int isAllOne, int isInv): Pre(Pre), Suf(Suf), Max(Max), isAllOne(isAllOne), isInv(isInv){}
	
	void fillWithOne(int n){
		Pre = Suf = Max = n;
		isAllOne = 1;
		isInv = 1;
	}
};

int n, m;
node tree[N << 2];

void merge(node &c, node &a, node &b){
	c.Max = max(max(a.Max, b.Max), a.Suf + b.Pre);
	c.Pre = a.Pre + (a.isAllOne? b.Pre: 0);
	c.Suf = b.Suf + (b.isAllOne? a.Suf: 0);
	c.isAllOne = a.isAllOne & b.isAllOne;
	// c.isAllOne = 0;
}

void push(int x, int l, int r){
	if (tree[x].isInv == 0){
		tree[2 * x + 1] = tree[2 * x] = node(0, 0, 0, 0, 0);
		tree[x].isInv = -1;
	}
	if (tree[x].isInv == 1){
		int mid = (l + r) >> 1;
		tree[2 * x].fillWithOne(mid - l + 1);
		tree[2 * x + 1].fillWithOne(r - mid);
		tree[x].isInv = -1;
	}
}

void upd(int L, int R, bool v, int x = 1, int l = 1, int r = n){
	// debug(L, R, v, x, l, r);
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		if (!v) tree[x] = node(0, 0, 0, 0, 0);
		else tree[x].fillWithOne(r - l + 1);
		return;
	}
	
	int mid = (l + r) >> 1;
	push(x, l, r);
	upd(L, R, v, 2 * x, l, mid);
	upd(L, R, v, 2 * x + 1, mid + 1, r);
	merge(tree[x], tree[2 * x], tree[2 * x + 1]);
}

int get(int p, int x = 1, int l = 1, int r = n){
	while (true){
		if (l == r){
			if (tree[x].isAllOne && p == 1){
				return l;
			}
			return -1;
		}
		// debug(tree[x].Max, p, x, l, r);
		if (tree[x].Max < p) return -1;
		
		int mid = (l + r) >> 1;
		push(x, l, r);
		if (tree[2 * x].Max >= p)
			r = mid, x *= 2;
		else
			if (tree[2 * x].Suf + tree[2 * x + 1].Pre >= p)
				return mid - tree[2 * x].Suf + 1;
		else 
			l = mid + 1, x = 2 * x + 1;
	}
}

void solve(){	
	cin >> n >> m;
	int cnt = 0;
	upd(1, n, 1);
	while (m--){
		char t; cin >> t;
		if (t == 'A'){
			int p; cin >> p;
			int x = get(p);
			// debug(p, x);
			// debug(x);
			if (x == -1) cnt++;
			else upd(x, x + p - 1, 0);
		}
		if (t == 'L'){
			int L, R; cin >> L >> R;
			upd(L, R, 1);
		}
	}
	cout << cnt;
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