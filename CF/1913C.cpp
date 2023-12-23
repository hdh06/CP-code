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

int const N = 30;

int cnt[N];

void solve(){	
	int m; cin >> m;
	while (m--){
		int t, x; cin >> t >> x;
		if (t == 1) cnt[x]++;
		if (t == 2){
			ll z = 0;
			for (int i = log2(x); i >= 0; i--){
				int c = cnt[i];
				for (int j = log2(c); j >= 0; j--) if ((1 << j) <= c && z + (1LL << j) * (1 << i) <= x)
					z += (1LL << j) * (1 << i), c -= 1 << j;
			}
			if (z == x) cout << "YES\n";
			else cout << "NO\n";
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