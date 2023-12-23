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

void solve(){	
	int n, k; cin >> n >> k;
	vl arr(n + 1);
		
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	int l = 0, r = 2e8, ans = 0;
	while (l <= r){
		int mid = (l + r) >> 1;
		bool flag = 0;
		for (int i = 1; i <= n; i++){
			ll sum = 0;
			for (int j = i, curr = mid; j <= n; j++, curr--){
				if (arr[j] >= curr) break;
				sum += curr - arr[j];
				if (j == n) sum = k + 1;
			}
			if (sum <= k) flag = 1;
		}
		
		if (flag) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	
	cout << ans << "\n";
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