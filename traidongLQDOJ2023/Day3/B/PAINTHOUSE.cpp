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
#define file "PAINTHOUSE"

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

int const N = 2e5 + 1;
int const MOD = 998244353;

int n;
int arr[N];

namespace sub1{
	bool check(){
		if (n > 8) return false;
		for (int i = 1; i <= n; i++) if (arr[i] > 8) return false;
		return true;
	}

	int const N = 1000;
	int dp[N][N];
	int calc(int i, int pre){
		if (i == n + 1) return 1;
		int &ans = dp[i][pre];
		if (ans != -1) return ans;
		ans = 0;
		for (int j = 1; j <= arr[i]; j++) if (j != pre)
			(ans += calc(i + 1, j)) %= MOD;
		return ans;
	}

	void solve(){
		memset(dp, -1, sizeof dp);

		cout << calc(1, 0) << "\n"; 
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	// if (sub1::check())
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!