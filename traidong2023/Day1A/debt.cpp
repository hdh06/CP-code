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
#define file "debt"

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

int const N = 101;
int const K = 1e4 + 1;
int const INF = 1e8;

int n, l, r, k;
int arr[N];


int dpL[N][N][K];
int dpR[N][N][K];

int calcL(int i, int j, int k){
	if (i >= l) return 0;
	if (j < l) return 0;
	if (k < 0) return -INF;
	
	if (dpL[i][j][k] != -1) return dpL[i][j][k];
	
	return dpL[i][j][k] = max(max(calcL(i + 1, j, k), calcL(i, j - 1, k)), calcL(i + 1, j - 1, k - (j - i)) + arr[i] - arr[j]);
}

int calcR(int i, int j, int k){
	if (i > r) return 0;
	if (j <= r) return 0;
	if (k < 0) return -INF;
	
	if (dpR[i][j][k] != -1) return dpR[i][j][k];
	
	if (k < 0) return INT_MIN;
	return dpR[i][j][k] = max(max(calcR(i + 1, j, k), calcR(i, j - 1, k)), calcR(i + 1, j - 1, k - (j - i)) - arr[i] + arr[j]);
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> n >> l >> r >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	memset(dpL, -1, sizeof dpL);
	memset(dpR, -1, sizeof dpR);
		
	int ans = 0;
	for (int i = l; i <= r; i++){
		for (int j = 0; j <= k; j++){
			ans = max(ans, calcL(1, i, j) + calcR(i + 1, n, k - j));
		}
	}

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!