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

int const N = 1e3 + 1;

int n;
int dp[N], c[N];x

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	
	int ans = 0;
	int pre = 1;
	int pos = 2;
	while (pos <= n){
		if (arr[pos] == arr[pre]) ans += pos - pre + 1, pre = pos + 1;
		pos++;
	}
	
	cout << dp[n] << "\n";
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