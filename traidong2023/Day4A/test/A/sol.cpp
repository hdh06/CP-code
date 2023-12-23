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
#define file "flie"

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

int const N = 2e5 + 5;

int n;
int arr[N];

namespace sub2{
	void solve(){
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			ll sum = 0;
			ll codd = 0;
			map<int, int> cnt;
			for (int j = i; j >= 1; j--){
				sum += arr[j];
				cnt[arr[j]]++;
				if (cnt[arr[j]] & 1) codd++;
				else codd--;
				if (codd == 0 && sum > 0)
					ans++;
			}
		}
		cout << ans << "\n";
	}
}

// namespace sub3{
	// int const D = 11;
	// int psum[N[2 * D + 5];
	// void solve(){
		// for (int i = 1; i <= n; i++)
			// psum[i][arr[i] + D]++;
// 		
		// for (int j = 0; j < 2 * D + 5; j++)
			// for (int i = 1; i <= n; i++)
				// psum[i][j] += psum[i - 1][j];
// 			
		// for (int i = 1; i <= n; i++){
// 			
		// }
	// }
// }
// 
int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	// if (n <= 2000)
		sub2::solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!