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
#define file "fiel"

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

bool const SINGLE_TEST = 0;

int const N = 2e5 + 1;
int const INF = 4e5 + 1;
z
int n;

int a[N];

int dp[N][2];

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 1; j++){
			dp[i][j] = INF;
			if (j != 1 || i - 1 > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j ^ 1] + (j == 0? a[i]: 0));
			if (i - 2 >= 0 && (j != 1 || i - 2 > 0))
				dp[i][j] = min(dp[i][j], dp[i - 2][j ^ 1] + (j == 0? a[i] + a[i - 1]: 0));
		}
		
	cout << min(dp[n][0], dp[n][1]) << "\n";
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
}//khong phai _HDH, _HDH ko xai template!!!