#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

void solve(){
	ll n, m; cin >> n >> m;
	
	ll k = 1;
	int cnt2 = 0, cnt5 = 0;
	{
		ll x = n;
		while (x % 2 == 0) x /= 2, cnt2++;
		while (x % 5 == 0) x /= 5, cnt5++;
	}
	
	while (cnt2 < cnt5 && k * 2 <= m) k *= 2, cnt2++;
	while (cnt5 < cnt2 && k * 5 <= m) k *= 5, cnt5++;
	while (k * 10 <= m) k *= 10;
	
	cout << (k == 1? n * m: n * k * (m / k)) << "\n";
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
}//it's coding time!