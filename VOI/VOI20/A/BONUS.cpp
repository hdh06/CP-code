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
#define file "BONUS"

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

int const N = 301;

int n, k;
int arr[N];

ll dp[N][N][N];

ll calc(int l, int r, int ck){
	if (r <= l)		
		return 0;

	ll &ans = dp[l][r][ck];
	if (ans != -1) return ans;
	ans = 0;
	if (r - l + 1 >= 2 && ck + 1 <= k){
		ans = max(ans, calc(l + 2, r, ck + 1) + abs(arr[l] - arr[l + 1]));
		ans = max(ans, calc(l, r - 2, ck + 1) + abs(arr[r] - arr[r - 1]));
		ans = max(ans, calc(l + 1, r - 1, ck + 1) + abs(arr[l] - arr[r]));
	}
	if ((k - ck) * 2 <= r - l){
		ans = max(ans, calc(l + 1, r, ck));
		ans = max(ans, calc(l, r - 1, ck));
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	memset(dp, -1, sizeof dp);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << calc(1, n, 0);
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!