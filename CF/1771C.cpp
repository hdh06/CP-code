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

vi p;
void init(){
	int z[100000] = {};
	for (ll i = 1; i <= 100000; i++) if (!z[i]){
		p.pb(i);
		for (ll j = i * i; j <= 100000; j += i)
			z[j] = 1;
	}
}

void solve(){
	int n; cin >> n;
	vi z;
	for (int j = 1; j <= n; j++){
		int x; cin >> x;
 
		if (x > 1) z.pb(x);
	}	
	
	n = z.size();
	sort(all(z));
	z.erase(unique(all(z)), z.end());
		
	cout << (z.size() != n? "YES\n" : "NO\n");
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	init();
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!