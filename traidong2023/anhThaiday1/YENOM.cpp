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
#define file "flie"

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

int const N = 2001;

int n; ll t;
int arr[N];

namespace sub3{
	int const T = 2e5 + 1;
	bool dp[T];
	void solve(){
		dp[0] = 1;	
		for (int i = 1; i <= n; i++)
			for (int j = arr[i]; j <= t; j++)
				dp[j] |= dp[j - arr[i]];
		ll ans = 0;
		for (int i = 0; i <= t; i++)
			ans += dp[i];
		cout << ans << '\n';
	}
}



namespace sub4{
	
	bool minimize(ll &x, ll v){
		if (x == -1 || x > v){
			x = v;
			return true;
		}
		return false;
	}
	
	ll dis[N];
	void solve(){
		sort(arr + 1, arr + n + 1);
	
		memset(dis, -1, sizeof dis);		
		dis[0] = 0;
		priority_queue<pll> que;
		
		que.push(mp(0LL, 0LL));
		
		while (!que.empty()){
			int v = que.top().nd;
			que.pop();
			for (int i = 1; i <= n; i++){
				if (minimize(dis[(v + arr[i]) % arr[1]], dis[v] + arr[i]))
					que.push(mp(-dis[(v + arr[i]) % arr[1]], (v + arr[i]) % arr[1]));
			}
		}
		
		ll ans = 0;
		for (int i = 0; i < arr[1]; i++) if (dis[i] != -1){
			// debug(i, dis[i]);
			ans += (max(0LL, t - dis[i] + 1) + arr[1] - 1) / arr[1];
			// debug(ans);
		}
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	// if (t <= 200000)	
		// sub3::solve();
	// else 
		sub4::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!