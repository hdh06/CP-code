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

bool const SINGLE_TEST = 1;

int const N = 5e5 + 1;

int n, c;
int arr[N];

vi g[N];

int cnt[N];

void solve(){	
	cin >> n >> c;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		cnt[i] = cnt[i - 1] + (arr[i] == c);
		g[arr[i]].pb(i);
	}
	
	int ans = 0;
	for (int i = 1; i < N; i++) if (i != c){
		vi z;
		if (g[i].size()) z.pb(1);
		for (int j = 1; j < g[i].size(); j++){
			z.pb(- cnt[g[i][j] - 1] + cnt[g[i][j - 1]]);
			z.pb(1);
		}
		
		int sum = 0;	
		for (auto x: z){
			sum += x;
			sum = max(sum, 0);
			ans = max(ans, sum);
		}
	}
	
	cout << cnt[n] + ans << "\n";
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