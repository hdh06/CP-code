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
#define file "camping"

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


int const K = 1e5 + 1;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int n, m, k;
ii arr[K];

namespace sub4{
	set<ii> ms, vis;
	ll ans = 0;
	
	void DFS(int i, int j){
		vis.insert({i, j});
		
		for (int d = 0; d < 4; d++){
			int g = i + dx[d], h = j + dy[d];
			
			if (vis.find({g, h}) != vis.end()) continue;
			
			if (1 <= g && g <= n && 1 <= h && h <= m)
				ans--;
			
			if (ms.find({g, h}) == ms.end()) continue;
			
			DFS(g, h);
		}
	}
	
	void solve(){
		for (int i = 1; i <= k; i++)
			ms.insert(arr[i]);
			
		ans = 1LL * (n - 1) * m + 1LL * (m - 1) * n;
		
		for (int i = 1; i <= k; i++) if (vis.find(arr[i]) == vis.end())
			DFS(arr[i].st, arr[i].nd);
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
	
	cin >> n >> m >> k;
	for (int i = 1; i < n; i++)
		cin >> arr[i].st >> arr[i].nd;
	
	sub4::solve();
	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!