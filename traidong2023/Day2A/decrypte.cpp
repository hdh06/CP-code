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
#define file "decrypte"

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

int const N = 10;
int const M = 21;

int n, k, m;

ll dp[N][1 << M];

ll calc(int i, ll curr){
	if (i == n) return curr == k;
	
	ll &ans = dp[i][curr];
	if (ans != -1) return ans;
	ans = 0;
	for (ll c = 1; c <= 26; c++)
		ans += calc(i + 1, ((curr * 33) ^ c) % (1LL << m));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> n >> k >> m;
	
	memset(dp, -1, sizeof dp);
	cout << calc(0, 0);
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!