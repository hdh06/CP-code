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

int const N = 11, M = 101;
int const MOD = 111539786;

int n, m, k, s;
bool isBan[M][N];

// int key(int i, int j){return i * 1000 + j;}

// namespace sub1{
	// vii p;
	// int link[N * 1000 + M];
// 	
	// void reset(int n){
		// for (int i = 1; i <= n; i++)
			// link[i] = i;
	// }
// 	
	// int find(int v){return link[v] = (link[v] == v? v: find(link[v]));}
// 	
	// bool unite(int a, int b){
		// a = find(a), b = find(b);
		// if (a == b) return false;
		// link[a] = b;
		// return true;
	// }
// 	
	// void solve(){
		// for (int i = 1; i <= n; i++)
			// for (int j = 1; j <= m; j++) if (!isBan[i][j]){
				// if (i + 1 <= n && !isBan[i + 1][j])
					// p.pb({key(i, j), key(i + 1, j)});	
				// if (j + 1 <= m && !isBan[i][j + 1])
					// p.pb({key(i, j), key(i, j + 1)});		
			// }
// 			
		// for (int mask = 0; mask < (1 << p.size()); mask++){
			// reset(p.size());
// 			
		// }
	// }
// }

namespace sub{
	int dp[M][N][2 * (M + 1) * (N + 1)];
	
	int calc(int i, int j, int c){
		// debug(i, j, c);
		if (i == 0) return c == 0;
		
		int &cnt = dp[i][j][c];
		if (cnt != -1) return cnt;
		cnt = 0;
		
		if (c >= 2){
			if (j > 1)
				cnt += calc(i, j - 1, c - 2);
			else cnt += calc(i - 1, n, c - 2);		
		}
		if (cnt >= MOD) cnt -= MOD;	
		
		if (c >= 1){
			if (!isBan[i][j] && i != m && !isBan[i + 1][j]){
				if (j > 1)
					cnt += calc(i, j - 1, c - 1);
				else cnt += calc(i - 1, n, c - 1);
			}
			if (cnt >= MOD) cnt -= MOD;	
			
			if (!isBan[i][j] && j != n && !isBan[i][j + 1]){
				if (j > 1)
					cnt += calc(i, j - 1, c - 1);
				else cnt += calc(i - 1, n, c - 1);
			}
			if (cnt >= MOD) cnt -= MOD;	
		}
		return cnt;
	}
	void solve(){
		memset(dp, -1, sizeof dp);	
		cout << calc(m, n, k + s + (n + 1) * (m + 1) - 1 - (n + m)) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> m >> n >> k >> s;
	for (int i = 1; i <= s; i++){
		int a, b; cin >> a >> b;
		isBan[a][b] = 1;  	
	}
	
	sub::solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!