#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	s = ' ' + s;
	int id = 1;
	vi p(n + 1), ps(n + 1);
	p[1] = id;
	for (int i = 2; i <= n; i++){
		if (s[i] != s[i - 1])
			p[i] = i, id = i;
		else p[i] = id;
		ps[i] = ps[i - 1] + s[i] - '0';
	}
	
	set<ii> ms;
	bool isO = 0;
	
	for (int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		if (p[r] - p[l] == 0)
			isO = 1;
		else if (s[r] == '1' && s[l] == '0' && ps[r] - ps[l - 1] == r - p[r] + 1)
			isO = 1;
		else{
			if (s[l] == '0') l = p[l];
			else if (l > 1 && s[l - 1] == '0') l = p[l - 1];
			if (s[r] == '1') r = p[r];
			else if (r < n && s[r + 1] == '1') r = p[r + 1];
			ms.insert({l, r});
			// debug(i, l, r);
		}
	}
	cout << ms.size() + isO << "\n";
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
}//it's coding time!