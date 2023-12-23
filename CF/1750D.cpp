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
int const MOD = 998244353;

void solve(){
	int n, m;
	cin >> n >> m;
	vi arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++)
		if (arr[i - 1] % arr[i] != 0){
			cout << "0\n";
			return;
		}
		
	int res = 1;

	debug(arr);

	for (int i = 2; i <= n; i++){
		int x = arr[i - 1] / arr[i];
		vi z;
		for (ll j = 2; j * j <= x; j++){
			if (x % j == 0){
				z.pb(j);
				while (x % j == 0) x /= j;
			}
		}
		if (x > 1) z.pb(x);
		
		int k = z.size();
		int ans = 0;
		for (int mask = 1; mask < (1 << k); mask++){
			int cnt = 0, tich = 1;
			for (int j = 0; j < k; j++) if (mask & (1 << j)){
				tich *= z[j];
				cnt++;
			}
			ans += (cnt & 1? 1: -1) * (m / arr[i]) / tich;
		}
		res = 1LL * res * (m / arr[i] - ans) % MOD;
	}
	cout << res << "\n";
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