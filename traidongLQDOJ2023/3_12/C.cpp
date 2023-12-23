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

int const N = 3001;

int n;
string s;

int id = 1;

vl g[N];

vl psum;

int get(int &i){
	int ans = 0;
	while ('0' <= s[i] && s[i] <= '9'){
		ans = 10 * ans + (s[i] - '0');
		i++;
	}
	return ans;
}

void solve(){	
	cin >> s;
	n = s.size();
	
	for (int i = 1; i <= n; i++) g[i].pb(1);
		
	ll cur = 1;
	psum.pb(0);
	for (int i = 0; i < n; i++){
		g[id].pb(get(i));
		cur *= g[id].back();
		if (s[i] == '+'){
			psum.pb(cur);
			cur = 1;
			id++;
		}
	}	
	// id++;
	psum.pb(cur);
	
	
	for (int i = 1; i <= id; i++)
		psum[i] += psum[i - 1];
	// debug(psum);
	
	// for (int i = 1; i <= id; i++)  g[i].pb(1);
		
	for (int i = 1; i <= id; i++) for (int j = 1; j < g[i].size(); j++)
		g[i][j] *= g[i][j - 1];
// 
	// for (int i = 1; i <= id; i++)
		// debug(g[i]);		
		
	ll ans = psum[id];
	for (int i = 1; i <= id; i++) for (int j = i + 1; j <= id; j++)
		for (int a = 1; a < g[i].size(); a++) for (int b = 1; b < g[j].size(); b++){
			ans = max(ans, psum[i - 1] + g[i][a - 1] * (g[i].back() / g[i][a - 1] + psum[j - 1] - psum[i] + g[j][b]) * (g[j].back() / g[j][b]) + psum[id] - psum[j]);
		}
	
	cout << ans << "\n";
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