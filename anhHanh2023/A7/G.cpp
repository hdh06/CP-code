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
#define file "divsubset"

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
template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int const N = 1001;

int sub;
int n; ll k;
ll arr[N];

namespace sub2{
	bool minimize(pll &x, pll v){
		if (x.st > v.st){
			x = v;
			return true;
		}
		if (x.st == v.st && x.nd > v.nd){
			x = v;
			return true;
		}
		return false;
	}
	pll dp[N][5 * N];
	int trace[N][5 * N];
	void solve(){
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < k; j++)
				dp[i][j] = mp(n + 1, 0);
		dp[1][1 % k] = mp(0, 0);
		
		for (int i = 1; i < n; i++)
			for (int j = 0; j < k; j++) if (dp[i][j].st < n + 1){
				if (minimize(dp[i + 1][j], dp[i][j])) trace[i + 1][j] = j;
				if (minimize(dp[i + 1][1LL * j * (arr[i + 1] % k) % k], mp(dp[i][j].st + 1, dp[i][j].nd + arr[i + 1])))
					trace[i + 1][1LL * j * (arr[i + 1] % k) % k] = j;
			}
	
		if (dp[n][0].st == n + 1){
			cout << -1;
			return;
		}
		
		vi ans;
		ll j = 0;
		for (int i = n; i >= 1; i--){
			if (dp[i][j] == dp[i - 1][j]) continue;
			ans.pb(i);
			j = trace[i][j];
		}
		
		cout << ans.size() << "\n";
		for (auto x: ans) cout << x << " ";
	}
}

namespace sub4{
	int const V = 6725;
	
	bool minimize(pll &x, pll v){
		if (x.st > v.st){
			x = v;
			return true;
		}
		if (x.st == v.st && x.nd > v.nd){
			x = v;
			return true;
		}
		return false;
	}
	pll dp[N][V];
	int trace[N][V];
	
	ll gcdA[N];
	vl divs;
	
	void solve(){
		if (k == 1){
			cout << "1\n";
			cout << (min_element(arr + 1, arr + n + 1) - arr);
			return;
		}
		
		for (int i = 1; i <= n; i++) gcdA[i] = gcd(arr[i], k);
		
		for (ll i = 1; i * i <= k; i++) if (k % i == 0){
			divs.pb(i);
			if (i != k / i) divs.pb(k / i);
		}
		
		sort(all(divs));
		
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < divs.size(); j++)
				dp[i][j] = mp(n + 1, 0);
				
		dp[0][0] = mp(0, 0);
		
		for (int i = 0; i < n; i++){
			// int d = 0;
			for (int j = 0; j < divs.size(); j++) if (dp[i][j].st < n + 1){
				
				if (minimize(dp[i + 1][j], dp[i][j])) trace[i + 1][j] = j;
				
				ll newGcd = divs[j] * gcd(k / divs[j], gcdA[i + 1]);
				// debug(divs[j], gcdA[i + 1], newGcd);
				int newJ = (newGcd == divs[j] || newGcd == k? (newGcd == k? divs.size() - 1: j): lb(1 + j + all(divs), newGcd) - divs.begin());
				// while (divs[d] < newGcd) d++;
				
				if (minimize(dp[i + 1][newJ], mp(dp[i][j].st + 1, dp[i][j].nd + arr[i + 1])))
					trace[i + 1][newJ] = j;
			}
		}
			
		// debug(divs);
				
		if (dp[n][divs.size() - 1].st == n + 1){
			cout << -1;
			return;
		}
		
		cout << dp[n][divs.size() - 1].st << "\n";
		int j = divs.size() - 1;
		for (int i = n; i >= 1; i--){
			if (dp[i][j] == dp[i - 1][j]) continue;
			cout << i << " ";
			j = trace[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> sub;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	sub4::solve();
	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!