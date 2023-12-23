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
#define file "PLAYDOM"

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

int const N = 2e6 + 1;

int n, d, t;
int arr[N];

namespace sub1{
	int const N = 501;
	int const INF = 1e5;
	int dp[N][N];
	int calc(int i, int k){
		if (k < 0) return INF;
		if (i == n + 1) return 0;
		int &ans = dp[i][k];
		if (ans != -1) return ans;
		ans = INF;

		int pre = INT_MAX - 1, cnt = 0;

		for (int j = i; j <= n; j++){
			int x = arr[j];
			if (pre + 1 < x) x = pre + 1;
			if (x <= t) cnt++;
			ans = min(ans, calc(j + 1, k - 1) + cnt);
			pre = x;
		}
		return ans;
	}

	void solve(){
		memset(dp, -1, sizeof dp);
		cout << calc(1, d + 1) << "\n";
	}
}

namespace sub2{
	void solve(){
		vi suf(n + 1);
		deque<int> que;
		for (int i = n; i >= 1; i--){
			while (!que.empty() && arr[i] + que.front() - i <= t)
				que.pof();
			if (arr[i] > t) que.pf(i);
			suf[i] = n - i + 1 - que.size();
		}

		int pre = INT_MAX - 1, cnt = 0;
		int ans = INT_MAX;
		for (int i = 1; i <= n; i++){
			int x = arr[i];
			if (x > pre + 1) x = pre + 1;
			if (x <= t) cnt++;
			if (i < n) ans = min(ans, cnt + suf[i + 1]);
			pre = x;
		}
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n >> d >> t;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	// if (n <= 500)
		sub1::solve();
	// else
	// 	sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!