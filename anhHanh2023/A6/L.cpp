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
#define file "raovat"

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

int const N = 500 * 500 + 1;
int const Q = 5e5 + 1;

ii h[N];
int b[N];

struct query{
	int l, r, w;
	int low, high;
	query(){}
	void read(){cin >> l >> r >> w;}
} queries[Q];
ii asks[Q];
int cnt[N];

struct node{
	int ans, pre, suf;
	bool allOne;
	node(){ans = pre = suf = allOne = 0;}
	node(int n){ans = pre = suf = n; allOne = 1;}
};

node merge(node L, node R){
	node X;
	X.ans = max(max(L.ans, R.ans), L.suf + R.pre);
	X.pre = L.pre + L.allOne * R.pre;
	X.suf = R.suf + R.allOne * L.suf;
	X.allOne = L.allOne & R.allOne;
	return X;
}

struct sgt{
	int n;
	vector<node> tree;
	
	sgt(){}
	sgt(int n) :n(n){
		tree.assign((1 << 19) + 1, node());
	}
	
	void upd(int pos){
		int x = 1, l = 1, r = n;
		while (l < r){
			int mid = (l + r) >> 1;
			if (pos > mid) x = 2 * x + 1, l = mid + 1;
			else x = 2 * x, r = mid;
		}
		
		tree[x] = node(1);
	
		while (x > 1){
			x >>= 1;
			tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
		}
	}
	
	node get(int L, int R, int x, int l, int r){
		if (r < L || R < l) return node(0);
		if (L <= l && r <= R) return tree[x];
		if (tree[x].allOne) return node(min(R, r) - max(L, l) + 1);
		
		int mid = (l + r) >> 1;
	
		return merge(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
	}
	
	int getMax(int L, int R){
		return get(L, R, 1, 1, n).ans;
	}
} stree;

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> h[i].st;
		h[i].nd = i;
		b[i] = h[i].st;
	}
	
	sort(h + 1, h + n + 1, greater<ii>());
	sort(b + 1, b + n + 1);
	// debug(vii(h + 1, h + n + 1));

	for (int i = 1; i <= q; i++)
		queries[i].read();
	
	for (int i = 1; i <= q; i++)
		queries[i].low = 1,
		queries[i].high = n;
	
	while (true){
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= q; i++){
			int l = queries[i].low, h = queries[i].high;
			if (l == h) continue;
			int mid = h - l == 1? h: (l + h) >> 1;
			cnt[mid]++;
		}
		
		for (int i = n - 1; i >= 0; i--)
			cnt[i] += cnt[i + 1];
		
		for (int i = 1; i <= q; i++){
			int l = queries[i].low, h = queries[i].high;
			if (l == h) continue;
			int mid = h - l == 1? h: (l + h) >> 1;
			asks[cnt[mid]--] = {mid, i};
		}
		
		if (!cnt[0]) break;
		
		stree = sgt(n);
		
		int i = 1;
		for (int j = 1; j <= cnt[0]; j++){
			ii x = asks[j];
			while (i <= n && h[i].st >= b[x.st]){
				stree.upd(h[i].nd);
				// debug("upd ", h[i].nd);
				i++;
			}
			
			// debug(stree.getMax(queries[x.nd].l, queries[x.nd].r), queries[x.nd].w);
			
			if (stree.getMax(queries[x.nd].l, queries[x.nd].r) >= queries[x.nd].w)
				queries[x.nd].low = x.st;
			else
				queries[x.nd].high = x.st - 1;
			// debug(queries[x.nd].low, queries[x.nd].high);
		}
	}
	
	for (int i = 1; i <= q; i++)
		cout << 1LL * b[queries[i].low] * queries[i].w << " ";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!