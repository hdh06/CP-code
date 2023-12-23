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

int n;
vii z;
vi g[N];

int tree[N];

void upd(int x, int val){
	for (;x < N; x += x & -x) tree[x] += val;
}
int get(int x){
	int ans = 0;
	for (;x > 0; x -= x & -x) ans += tree[x];
	return ans;
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;	
		z.pb({x, y});
	}
	
	{
		vi b;
		for (auto x: z) b.pb(x.st);
		sort(all(b));
		b.erase(unique(all(b)), b.end()); 
		for (auto &x: z) x.st = lb(all(b), x.st) - b.begin() + 1;
	}
	
	{
		vi b;
		for (auto x: z) b.pb(x.nd);
		sort(all(b));
		b.erase(unique(all(b)), b.end()); 
		for (auto &x: z) x.nd = lb(all(b), x.nd) - b.begin() + 1;
	}
	
	for (auto x: z) g[x.st].pb(x.nd);
	
	
	int ans = 0;
	int j = N - 1;
	for (int i = 1; i < N; i++) if (g[i].size()){
		for (auto x: g[i]) upd(x, 1);
		while (get(j - 1) >= n / 2) j--;
		if (j >= *min_element(all(g[i])) && get(j) == n / 2) ans++;
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