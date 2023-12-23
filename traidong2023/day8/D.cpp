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
#define file "discounts"

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

int const N = 220797 + 1;

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	int n; cin >> n;
	vi a, b;
	for (int i = 1; i <= n; i++){
		int x, t; cin >> x >> t;
		if (t == 1) a.pb(x);
		if (t == 2) b.pb(x);
	}
	
	vi ans[N] = {};
	int id = 0;
	
	sort(all(a), greater<int>());
	sort(all(b), greater<int>());
	int k = 0;

	while (k < min(a.size(), b.size())){
		ans[]
		k++;
	}
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!