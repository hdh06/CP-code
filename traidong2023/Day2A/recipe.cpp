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
#define file "recipe"

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

int const N = 2e5 + 1;

struct query{
	int l, r, x;
	query(){}
	
	void read(){cin >> l >> r >> x;}
};

int n, q;
ll arr[N];

query queries[N];

namespace sub1{
	ll dp[N];
	void solve(){
		for (int k = 1; k <= q; k++){
			for (int i = queries[k].l; i <= queries[k].r; i++)
				arr[i] += queries[k].x;
			
	
			for (int i = 1; i <= n; i++){
				ll maxx = arr[i], minn = arr[i];
				dp[i] = dp[i - 1];
				for (int j = i - 1; j >= 1; j--){
					maxx = max(maxx, arr[j]);
					minn = min(minn, arr[j]);
					
					dp[i] = max(dp[i], dp[j - 1] + maxx - minn);
				}
			}	
			
			cout << dp[n] << "\n";
		}
	}
}

namespace sub2{
	void solve(){
		for (int k = 1; k <= q; k++){
			for (int i = queries[k].l; i <= queries[k].r; i++)
				arr[i] += queries[k].x;
			
			ll ans = 0;
			ll last = arr[1];
			arr[n + 1] = LLONG_MAX;
			for (int i = 1; i <= n; i++){
				if (arr[i] < arr[i + 1]){
					ans += last - arr[i];
					last = arr[i + 1];
				}
			}	
			// debug(vi(arr + 1, arr + n + 1));	
	
			cout << ans << "\n";
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

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= q; i++)
		queries[i].read();
		
	sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!