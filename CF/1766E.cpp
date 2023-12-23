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

int const N = 3e5 + 1;

int n;
int arr[N];
ll dp[N][4 * 4 * 4];

pair<bool, int> next(int mask, int pos){
	if (arr[pos] == 0)
		return {1, mask};
		
	int p = 1; int tmp = mask;
	for (int i = 0; i < 3; i++){
		int d = tmp % 4;
		if (d == 0 || d & arr[pos]){
			mask -= d * p;
			mask += arr[pos] * p;
			return {d == 0, mask};
		}
		tmp /= 4;
		p *= 4;
	}
	assert(0);	
}

ll calc(int i, int mask){
	if (i == n + 1) return 0;
	if (dp[i][mask] != -1) return dp[i][mask];
	pair<bool, int> p = next(mask, i);
	return dp[i][mask] = 1LL * p.st * (n - i + 1) + calc(i + 1, p.nd);
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	memset(dp, -1, sizeof dp);
	
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += calc(i, 0);
	
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