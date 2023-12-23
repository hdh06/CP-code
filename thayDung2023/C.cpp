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

int const N = 201;

struct edge{
	int a, b;
	ll d, w;
	edge(){}
	edge(int a, int b, ll d, ll w) :a(a), b(b), d(d), w(w) {}
};
	
int n, m;
ll c1, c2;

vector<edge> edl;

int link[N];
int find(int v){return link[v] = link[v] != v? find(link[v]): v;}

bool unite(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return false;
	link[a] = b;
	return true;
}

bool minimize(ll &x, ll v){
	if (x == -1 || x > v){
		x = v;
		return true;
	}
	return false;
}

void solve(){	
	cin >> n >> m;
	cin >> c1 >> c2;
	vl z;
	for (int i = 1; i <= m; i++){
		int a, b; 
		ll d, w;
		cin >> a >> b >> d >> w;
		edl.pb(edge(a, b, d, w));
		z.pb(d);
	}
	
	sort(all(edl), [](edge a, edge b){
		return a.w < b.w;
	});
	
	sort(all(z));
	
	ll ans = -1;
	for (ll dl: z){
		for (int i = 1; i <= n; i++) link[i] = i;
		
		ll maxW = 0;
		int cnt = 0;
		for (edge e: edl) if (e.d <= dl)
			if (unite(e.a, e.b)){
				maxW = max(maxW, e.w);
				cnt++;
			}
			
		if (cnt < n - 1) continue; 
			
		minimize(ans, dl * c1 + maxW * c2);
	}
	cout << ans;
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