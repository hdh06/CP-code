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

int const N = 1e5 + 1;

int n;
vi g[N];

int tin[N];

vi A, B;

void DFS(int v, int p = -1){
	for (auto u: g[v]){
		if (tin[u] && tin[v] - tin[u] == 2 && !A.size()){
			//u v p
			A.pb(u); A.pb(v); A.pb(p);
			return;
		}
		if (tin[u]) continue;
		tin[u] = tin[v] + 1;
		DFS(u, v);
	}
}

void DF2(int v, int p = -1){
	// debug(v, p);
	for (auto u: g[v]){
		if (tin[u] && tin[v] - tin[u] == 2 && !B.size()){
			//u v p
			B.pb(u); B.pb(v); B.pb(p);
			if (A == B){
				B.clear();
				continue;
			}
			return;
		}
		if (tin[u]) continue;
		tin[u] = tin[v] + 1;
		DF2(u, v);
	}
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= 2 * n - 3; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	DFS(1);
	if (A.size() < 3){
		cout << -1;
		return;
	}
	
	memset(tin, 0, sizeof tin);

	DF2(1);
	// debug(vi(tin + 1, tin + n + 1));
	if (B.size() < 3){
		cout << -1;
		return;
	}

	
	cout << 3 << "\n";
	for (auto x: A) cout << x << " "; cout << "\n";
	for (auto x: B) cout << x << " "; cout << "\n";
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