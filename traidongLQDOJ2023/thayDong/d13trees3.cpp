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

int const N = 3e5 + 1;

int n; ll w;
ii arr[N];

int dp[N];

bool f(int mid){
	deque<int> que;
		
	int k = 1;
	for (int i = 1; i <= n; i++){
		while (arr[i].st - arr[k].st > mid){
			if (!que.empty() && que.front() == k) que.pof();
			k++;
		}
		// debug(k, i);
		dp[i] = (que.empty()? 0: dp[que.back()]) + arr[i].nd;
		// debug(i, dp[i]);
		while (!que.empty() && dp[que.back()] < dp[i]) que.pob();
		que.pb(i);
	}	
	
	return *max_element(dp + 1, dp + n + 1) >= w;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> arr[i].st;
	for (int i = 1; i <= n; i++) cin >> arr[i].nd;
	
	sort(arr + 1, arr + n + 1);
	
	// debug(vii(arr + 1, arr + n + 1));
	
	int ans = -1;
	for (int l = 0, r = 1e9; l <= r;){
		int mid = l + (r - l) / 2;
		if (f(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	// debug(f(2));
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!