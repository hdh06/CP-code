#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 2020
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
#define file "gates"

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

void solve(){	
	int n; cin >> n;
	string s; cin >> s;
	
	set<pair<ii, ii> > edge;
	set<ii> node;
	
	ii pre = {0, 0};
	node.insert(pre);
	int x = 0, y = 0;
	int ans = 0;
	for (auto c: s){
		if (c == 'N') x--;
		if (c == 'S') x++;
		if (c == 'W') y--;
		if (c == 'E') y++;
		
		if (edge.find({{x, y}, pre}) == edge.end() && node.find({x, y}) != node.end()) ans++;
		
		edge.insert({{x, y}, pre});
		edge.insert({pre, {x, y}});
		node.insert({x, y});
		
		pre = {x, y};
 	}
 	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef LOCAL
		cerr << "USACO is fun haha\n";
	#else
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!