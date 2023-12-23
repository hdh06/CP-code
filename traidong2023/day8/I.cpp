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
#define file "costquery"

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

int const N = 1e5 + 1;

struct edge{
	int a, b, w;
	edge() {}
	void read(){cin >> a >> b >> w;}
};

int n, q;
edge edges[N];

vector<edge> g[N];

ll cnt[N];

int link[N];
int sz[N];

int find(int v){return link[v] = link[v] == v? v: find(link[v]);}

bool unite(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return false;
	link[a] = b;
	sz[b] += sz[a];
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> n >> q;
	for (int i = 1; i < n; i++)
		edges[i].read();

	vi b;
	for (int i = 1; i < n; i++) b.pb(edges[i].w);
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	
	for (int i = 1; i < n; i++){
		int k = lb(all(b), edges[i].w) - b.begin();
		g[k].pb(edges[i]);
	}
	
	iota(link + 1, link + n + 1, 1);
	fill(sz + 1, sz + n + 1, 1);
	
	for (int i = 0; i < n; i++){
		for (auto e: g[i]){
			int a = sz[find(e.a)], b = sz[find(e.b)];
			if (unite(e.a, e.b)){
				cnt[i] += 1LL * a * b;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		cnt[i] += cnt[i - 1];
		
	// debug(b); 
		
	while (q--){
		int l, r; cin >> l >> r;
		l = lb(all(b), l) - b.begin() - 1;
		r = ub(all(b), r) - b.begin() - 1;
	
		
		if (l == -1) cout << cnt[r] << " ";
		else cout << cnt[r] - cnt[l] << " ";
	}

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!