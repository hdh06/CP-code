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
#define file "SPLCAN"

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

int const N = 1e5 + 1;

int m, n;
int arr[N];

namespace sub1{
	void solve(){
		priority_queue<int> que;
		for (int i = 1; i <= n; i++) que.push(arr[i]);
		while (m--){
			if (!que.empty()){
				int x = que.top(); que.pop();
				if (x - 1 > 0) que.push(x - 1);
			}
		}
		ll ans = 0;
		while (!que.empty()){
			int x = que.top(); que.pop();
			ans += 1LL * x * x;
		}
		cout << ans << "\n";
	}
}

namespace sub4{
	ll f(int mid){
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			ans += max(0, arr[i] - mid);
		return ans;
	}

	void solve(){
		int ans = -1;
		for (int l = 0, r = 2e9; l <= r; ){
			int mid = l + (r - l) / 2;
			if (f(mid) <= m){
				ans = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		m -= f(ans);
		for (int i = 1; i <= n; i++){
			if (arr[i] > ans) arr[i] = ans;
			if (m && arr[i] == ans && arr[i] > 0) m--, arr[i]--;
		}
		ll res = 0;
		for (int i = 1; i <= n; i++) res += 1LL * arr[i] * arr[i];
		cout << res << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".ans", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	// if (m <= 200000)
		sub1::solve();
	// else
	// 	sub4::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!