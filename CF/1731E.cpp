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

int const N = 1e6 + 1;

ll dp[N];

void solve(){
	ll n, m; cin >> n >> m;
	for (int i = n; i >= 1; i--){
		dp[i] = (n / i) * (n / i - 1) / 2;
		for (int j = 2 * i; j <= n; j += i)	
			dp[i] -= dp[j];
	}
	
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i] / (i - 1);
		
	ll cnt = 0, rmd = m;
	for (int i = n; i >= 2; i--){
		cnt += min(dp[i], rmd / (i - 1));
		rmd -= min(dp[i], rmd / (i - 1)) * (i - 1);
	}
	if (rmd > 0)
		cout << "-1\n";
	else cout << m + cnt << "\n";
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