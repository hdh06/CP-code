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

int const N = 1e4 + 1;
int n, m;
int q;

namespace sub1{
	int const N = 701;
	int dis[N][N];
	
	bool minimize(int &x, int val){
		if (val == -1) return false;
		if (x == -1 || x > val){
			x = val;
			return true;
		}
		return false;
	}
	
	void solve(){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = (i != j);

		for (int i = 1; i <= m; i++){
			int a, b; cin >> a >> b;
			dis[a][b] = dis[b][a] = -1;
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) if (dis[i][k] != -1 && dis[k][j] != -1) 
					minimize(dis[i][j], dis[i][k] + dis[k][j]);
		cin >> q;
		while (q--){
			int a, b; cin >> a >> b;
			cout << dis[a][b] << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> n >> m;
	if (n <= 700)
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!