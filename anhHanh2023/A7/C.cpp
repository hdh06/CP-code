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
#define file "winterfashion"

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

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	int n, k; cin >> n >> k;

	vi arr(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		if (arr[i] < 20) k--, arr[i] = 1;
		else arr[i] = 0;
	}	

	
	if (k < 0){
		cout << -1;
		return 0;
	}
	
	int pre = 1;
	vi z;
	for (int i = 1; i <= n; i++){
		if (arr[i] == 1){
			if (i - pre) z.pb(i - pre);	
			pre = i + 1;
		}
	}
	if (n + 1 - pre) z.pb(n + 1 - pre);
	
	sort(all(z));
	int ans = z.size() * 2;
	debug(z);
	if (arr[1] == 1) ans--;
	// if (arr[n] == 1)ans--;
	debug(ans);
	
	for (auto x: z) if (k >= x){
		k -= x;
		ans -= 2;
	}
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!