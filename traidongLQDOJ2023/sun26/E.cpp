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

int n, q, k;
ii a[N];
int p[N];

void solve(){	
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++) a[i].st = i;
	
	while (q--){
		int l, r; cin >> l >> r;
		for (int i = l; i <= r; i++) a[i].nd = p[i - l + 1];
		sort(a + l, a + r + 1, [](ii x, ii y){
			return x.nd < y.nd;
		});
	// debug(vii(a + 1, a + n + 1));
	}
	
	
	cout << a[k].st << "\n";
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