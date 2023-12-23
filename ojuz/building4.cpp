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

int const N = 4e3 + 5;

int n; 	
int arr[N][2] = {};

int dp[N][N][2] = {};

bool emrua(int i, int cnt, int last){
	if (i == 2 * n + 1) return dp[i][cnt][last] = (cnt == 0);
		
	if (dp[i][cnt][last] != -1) return dp[i][cnt][last];

	bool x = 0, y = 0;
	if (arr[i - 1][last] <= arr[i][0] && cnt)
		x = emrua(i + 1, cnt - 1, 0);
	if (arr[i - 1][last] <= arr[i][1])
		y = emrua(i + 1, cnt    , 1);
			
	return dp[i][cnt][last] = x | y;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> arr[i][0];
	for (int j = 1; j <= 2 * n; j++) cin >> arr[j][1];
		
	memset(dp, -1, sizeof dp);
		
	if (!emrua(1, n, 0)){
		cout << -1;
		return;
	}
	for (int i = 1, j = n; i <= 2 * n; i++){
		if (j && dp[i + 1][j - 1][0]){
			cout << 'A'; j--;
		}else cout << 'B';
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