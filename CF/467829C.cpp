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
#define file "MAXMIN"

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

int const N = 5e5 + 1;
int const MOD = 1e9 + 7;

int n;
int arr[N];

namespace sub1{
	void solve(){
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				for (int k = j + 1; k <= n; k++)
					for (int z = k; z <= n; z++){
						int maxx = 0, minn = INT_MAX;
						for (int d = i; d <= j; d++)
							maxx = max(maxx, arr[d]);
						
						for (int d = k; d <= z; d++)
							minn = min(minn, arr[d]);
						(ans += 1LL * minn * maxx % MOD) %= MOD;
					}
		cout << ans;
	}
}

namespace sub2{
	void solve(){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			int sum_suf = 0;
			for (int j = i + 1; j <= n; j++){
				int minn = INT_MAX;
				for (int k = j; k <= n; k++){
					minn = min(minn, arr[k]);
					(sum_suf += minn) %= MOD;
				}
			}
			
			int maxx = 0;
			for (int j = i; j >= 1; j--){
				maxx = max(maxx, arr[j]);
				(ans += 1LL * maxx * sum_suf % MOD) %= MOD;
			}
		}
		cout << ans;
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	if (n <= 50) 
		sub1::solve();
	else if (n <= (int)5e2)
		sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!