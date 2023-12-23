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

int const MOD = 998244353;

int const N = 3e5 + 1;
int const L = 19;

int n;
int arr[N];
int spt[N][L];

int get(int l, int r){
	int k = log2(r - l + 1);
	if (spt[l][k] < spt[r - (1 << k) + 1][k])
		return spt[l][k];
	return spt[r - (1 << k) + 1][k];
}

int dp[N];

struct P{
	ll x, y;
	
	P(){}
	P(ll x, ll y): x(x), y(y) {}
	
	double dis(){return sqrt(x * x + y * y);}
	ll dis2(){return x * x + y * y;}
	ll dot(P A){return x * A.x + y * A.y;}
	ll cross(P A){return x * A.y - y * A.x;}
	double angle(){return y >= 0? acos(x / dis()): 8 * atan(1) - acos(x / dis());}
	double angle(P A){return acos(dot(A) / dis() / A.dis());}
	P operator -(P A){return P(x - A.x, y - A.y);}
	P operator +(P A){return P(x + A.x, y + A.y);}
	P operator *(ll v){return P(x * v, y * v);}
	P operator /(ll v){assert(v != 0);return P(x / v, y / v);}
	
	void read(){cin >> x >> y;}
	void flip90cw(){x = -x, swap(x, y);}
	void flip90cww(){y = -y, swap(x, y);}
	void flip180(){x = -x, y = -y;}
};

int calc(int l, int r){
	if (l == r) return 1;
	int x = get(l, r);
	int &ans = dp[x];
	if (dp[x] != -1) return dp[x];
	int L = 1, R = 1;
	if (x - 1 >= l){
		L += 2 * calc(l, x - 1) % MOD; if (L >= MOD) L -= MOD;
		int pos = get(l, x - 1);
		if (pos + 1 <= x - 1)
			L -= calc(pos + 1, x - 1); if (L < 0) L += MOD;
	}
	if (x + 1 <= r){
		R += 2 * calc(x + 1, r) % MOD; if (R >= MOD) R -= MOD;
		int pos = get(x + 1, r);
		if (pos - 1 >= x + 1)
			R -= calc(x + 1, pos - 1); if (R < 0) R += MOD;
	}

	return ans = 1LL * L * R % MOD;
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) spt[i][0] = i, dp[i] = -1;
	
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= n; i++)
			if (arr[spt[i][j - 1]] < arr[spt[min(n, i + (1 << (j - 1)))][j - 1]])
				spt[i][j] = spt[i][j - 1];
			else spt[i][j] = spt[min(n, i + (1 << (j - 1)))][j - 1];
			
	cout << calc(1, n) << "\n";
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