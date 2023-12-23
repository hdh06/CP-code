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

bool const SINGLE_TEST = 0;

ll calc(ll s, ll k){
	// (s + 20 * x)(k - 4 * x) = -80x^2 + (20k - 4s) * x + s * k
	ll ans = s * k;
	ll x = (5 * k - s) / 40;// -b / 2a
	x = min(x, k / 4);
	
	for (int i = 1; i <= 4; i++){
		if (x >= 0) ans = max(ans, (s + 20 * x) * (k - 4 * x));
		x = min(x + 1, k / 4);
	}
	return ans;
}

void solve(){		
	ll s, k; cin >> s >> k;
	ll ans = s * k;
	if (s % 5 == 0){
		if (s % 10 != 0) ans = max(ans, (s + 5) * (k - 1));
	}else{
		while (s & 1) s += s % 10, k--;
		for (int i = 1; i <= 4; i++){
			if (k >= 0) ans = max(ans, calc(s, k));
			s += s % 10, k--;
		}
	}
	cout << ans << "\n";
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