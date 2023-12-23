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
#define file "SHEEP"

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

int const N = 5e5 + 1;

int n, k;
vi g[N];
vi pos;
	
namespace sub1{
	void solve(){
		cout << (n + 1) / 2;
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 1; i <= k; i++){
		int x; cin >> x;
		pos.pb(x);
	}
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!