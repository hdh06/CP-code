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

map<int, int> cnt;
vi prime;
vl factor, dp;
void gen(int i, ll t){
	if (i == prime.size()){
		factor.pb(t);
		return;
	}
	ll p = 1;
	for (int j = 0; j <= cnt[prime[i]]; j++){
		gen(i + 1, t * p);
		p *= prime[i];
	}
}

void solve(){
	cnt.clear(), prime.clear(), factor.clear();
	ll n, m1, m2; cin >> n >> m1 >> m2;
	
	for (ll i = 2; i * i <= m1; i++)
		while (m1 % i == 0) m1 /= i, cnt[i]++;
	if (m1 > 1) cnt[m1]++;
	
	for (ll i = 2; i * i <= m2; i++)
		while (m2 % i == 0) m2 /= i, cnt[i]++;
	if (m2 > 1) cnt[m2]++;
	
	for (auto x: cnt)
		prime.pb(x.st);
	
	gen(0, 1);
	sort(all(factor));
	
	int ans = 0; ll sxor = 0;
	dp.resize(factor.size());
	for (int i = 0; i < factor.size(); i++){
		ll f = factor[i];
		if (f <= n)
			dp[i] = f;
		else{
			dp[i] = 1;
			for (auto j: prime) if (f % j == 0)
				dp[i] = max(dp[i], dp[lb(all(factor), f / j) - factor.begin()]);
		}
		if (f / dp[i] <= n) ans++, sxor ^= f / dp[i];
	}
	cout << ans << " " << sxor << "\n";
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