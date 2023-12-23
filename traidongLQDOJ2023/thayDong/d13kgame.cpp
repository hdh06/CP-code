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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

int const N = 1e4 + 1, K = 101;
int const Z = 1e6 + 1;

int n, k;
bool vis[Z][K];
bool dp[Z][K];

bool calc(int n, int pre){
	if (n == 0) return 0;
	bool &ans = dp[n][pre];
	if (vis[n][pre]) return ans;
	vis[n][pre] = 1;
	ans = 0;
	for (int j = min(k, n); j >= 1; j--) if (j != pre)
		if (calc(n - j, j) == 0){
			ans = 1;
			break;
		}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> n >> k;
		
	vi z(N, 0);
	int x = 0, y = 0, l = N;
	for (int i = 1; i < N; i++){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (i + z[i] < N && calc(z[i], 0) == calc(i + z[i], 0)) x = i, y = i + z[i], z[i]++;
		if (i + z[i] == N){
			l = i;
			break;
		}
	}

	n %= l;
	cout << calc(n, 0);
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!
