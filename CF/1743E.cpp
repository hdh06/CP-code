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

bool const SINGLE_TEST = 1;

int const N = 5001;

ll p1, t1;
ll p2, t2;
ll h, s;

ll dp[N];

ll calc(ll h){
	if (h <= 0) return 0;
	
	if (dp[h] != -1) return dp[h];
	
	ll ans = LLONG_MAX;
	
	for (int i = 0; i <= h; i++){
		ll z1 = (p1 - s) * i + (p2 - s) * (i * t1 / t2);
		ll z2 = (p2 - s) * i + (p1 - s) * (i * t2 / t1);
		if (h - z1 <= 0) ans = min(ans, t1 * i);
		if (h - z2 <= 0) ans = min(ans, t2 * i);
		ans = min(ans, calc(h - z1 - p1 - p2 + s) + t1 * i + max(t1, t2 - i * t1 % t2));
		ans = min(ans, calc(h - z2 - p1 - p2 + s) + t2 * i + max(t2, t1 - i * t2 % t1));		
	}
	
	return dp[h] = ans;
}

void solve(){
	cin >> p1 >> t1;
	cin >> p2 >> t2;
	cin >> h >> s;
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(h);	
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