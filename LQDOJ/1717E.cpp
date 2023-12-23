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

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

bool const SINGLE_TEST = 1;

int const MOD = 1e9 + 7;

int const N = 1e5 + 1;
int memo[N];

int euler(int x){
	if (x == 1) return 0;
	if (memo[x] != -1) return memo[x];
	int &ans = memo[x] = x;
	for (ll i = 2; i * i <= x; i++){
		if (x % i == 0){
			while (x % i == 0) x /= i;
			ans -= ans / i; 
		}
	}
	if (x > 1) ans -= ans / x;
	return ans;
}

void solve(){
	int n; cin >> n;
	
	memset(memo, -1, sizeof memo);
	
	int ans = 0;
	for (ll c = 1; c <= n - 2; c++){
		for (ll i = 1; i * i <= n - c; i++) if ((n - c) % i == 0){
			(ans += 1LL * lcm(c, i) * euler((n - c) / i) % MOD) %= MOD;
			if ((n - c) / i != i) (ans += 1LL * lcm(c, (n - c) / i) * euler(i) % MOD) %= MOD;
		}
	}
	cout << ans;
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