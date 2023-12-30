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

int const N = 31;

int a[N][N], b[N][N];

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) b[i][j] = a[i][j];
		for (int i = 1; i <= n; i++) if (b[k][i] == 2) b[k][i] = 1, b[i][k] = 1;
		vii z;
		for (int i = 1; i <= n; i++) if (i != k){
			int cnt = 0;
			for (int j = 1; j <= n; j++) if (b[i][j] == 1) cnt++;
			z.pb(mp(cnt, i));
		}
		sort(all(z));
		for (auto x: z){
			
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