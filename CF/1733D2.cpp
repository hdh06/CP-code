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

int const N = 5002;

ll n, x, y;
string a, b;
bool c[N];

ll dp[2][N][N];

void minimize(ll &dp, ll v, ll del){
	if (v == -1) return;
	if (dp == -1) dp = v + del;
	else dp = min(dp, v + del);
}

void solve(){
	cin >> n >> x >> y;
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	
	if (y <= x){
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] != b[i]) cnt++;
		if (cnt & 1){
			cout << "-1\n";
			return;
		}
	 
		ll ans = (cnt / 4) * y * 2;
		cnt %= 4;
		if (cnt == 2){
			bool flag = 0;
			for (int i = 1; i <= n; i++) if (!flag)
				for (int j = i + 2; j <= n; j++){
					if (a[i] != b[i] && a[j] != b[j]){
						ans += y;
						flag = 1;
						break;
					}
				}
			if (!flag) ans += min(x, 2 * y);
		}
		cout << ans << "\n";
	}else{
	
		for (int i = 1; i <= n; i++)
			c[i] = (a[i] != b[i]);
		
		for (int b = 0; b <= 1; b++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					dp[b][i][j] = -1;
			
		if (c[1]){
			dp[1][1][1] = 0;
		}else dp[0][1][0] = 0;
		
		for (int i = 2; i <= n; i++){
			for (int j = 0; j <= n; j++){
				if (c[i]){
					//dp[0][i][j]
					if (j){
						minimize(dp[0][i][j], dp[0][i - 1][j - 1], x);
						minimize(dp[0][i][j], dp[1][i - 1][j - 1], y);
					}
					if (j < i){
						minimize(dp[0][i][j], dp[0][i - 1][j + 1], y);
						minimize(dp[0][i][j], dp[1][i - 1][j + 1], x);				
					}
					
					//dp[1][i][j]
					if (j){
						minimize(dp[1][i][j], dp[0][i - 1][j - 1], 0);
						minimize(dp[1][i][j], dp[1][i - 1][j - 1], 0);
					}
				}else{
					//dp[0][i][j]
					minimize(dp[0][i][j], dp[0][i - 1][j], 0);
					minimize(dp[0][i][j], dp[1][i - 1][j], 0);
					
					//dp[1][i][j]
					minimize(dp[1][i][j], dp[0][i - 1][j], y);
					minimize(dp[1][i][j], dp[1][i - 1][j], x);
					if (j > 1){
						minimize(dp[1][i][j], dp[0][i - 1][j - 2], x);
						minimize(dp[1][i][j], dp[1][i - 1][j - 2], y);
					}
				}
			}
		}
		cout << dp[0][n][0] << "\n";
	}
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