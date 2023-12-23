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

int const N = 101;
int const MOD = 998244353;
int n;
int arr[N][N];

bool check(int i, int j){
	for (int k = 1; k <= i; k++){
		if (arr[k][i] == 0) continue;
		if (arr[k][i] == 1 && k <= j) return false;
		if (arr[k][i] == 2 && k > j) return false;
	}
	return true;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++)
			cin >> arr[i][j];
	}
	
	int dp[N][N] = {};
	dp[1][0] = (arr[1][1] != 2) * 2;
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < i; j++){
			if (check(i, j)) (dp[i][j] += dp[i - 1][j]) %= MOD;
			if (check(i, i - 1)) (dp[i][i - 1] += dp[i - 1][j]) %= MOD;
		} 	
	}
	
	int ans = 0;
	for (int i = 0; i <= n; i++)
		(ans += dp[n][i]) %= MOD;
			
	cout << ans;
}

//1 0 2
//0 1 0
//0 0 1

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