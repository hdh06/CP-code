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

int const N = 2e5 + 5;
int n;
int arr[N];

int dp[N][2][2];

int calc(int i, bool is1, bool is2){;
	if (i >= n + 1) return 0;
	
	int &ans = dp[i][is1][is2];
	if (ans != -1) return ans;
	ans = INT_MAX;
	
	ans = min(ans, calc(i + 1, 0, 0) + 1 - is2);
	if (arr[i] - is1) ans = min(ans, calc(i + 1, 0, 1) + 1 - is2);
	if (arr[i + 1]) ans = min(ans, calc(i + 1, 1, 0));
	return ans;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	memset(dp, -1, sizeof dp);
		
	cout << calc(1, 0, 0) << "\n";
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